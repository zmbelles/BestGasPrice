/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;
class Container{
private:
    vector<float> prices;
    vector<float> distances;
    int size;
public:
    Container();
    void split_c(string);
    void process();
};
Container::Container(){
    
}
void Container::process(){
    //control gas price
    int c0;
    //other gas prices
    float c1;
    //cost to fill control tank   
    float t0;
    //cost to fill "cheaper" tank
    float t1;
    vector<float> best;
    int p;
    //size of gas tank
    int a;
    //extra distance to "cheaper" gas
    float d;
    //vehicles mpg
    int m;
    cout<<"How much is the price of gas at your go to station?" << endl;
    cin >> c0;
    cout << "what is the mpg of your vehicle?"<<endl;
    cin >> m;
    cout << "how many gallons are in your vehicles tank?" << endl;
    cin >> a;
    t0 = c0*a;
    best[2]=t0;
    //calculation for base price
    
    for(int i=0; i<size;i++){
        c1 = prices[i];
        d = distances[i];
        
        int tmp;
        tmp = c1*a;
        t1=tmp;
        t1+=(d/m)*c1;
        if((t0-t1)>best[2]){
            best[0]=t1;
            best[1]=d;
            best[2]=t0-t1;
        }
    }
}
void Container::split_c(string str)
{
    string w = "";
    for (auto x : str)
    {
        if (x == ',')
        {
            float price = stof(w);
            prices.push_back(price);
            w = "";
        }
        else {
            w = w + x;
        }
    }
    float distance = stof(w);
    distances.push_back(distance);
    size++;
}
int main()
{
    //parallel vector processing
    vector<float> prices;
    vector<float> distances;
    
    Container c;
    
    cout << "Please enter all prices and distances separated by a comma and press enter after each entry. when finished, type 0,0." << endl;
    cout << "Ex. 5.45,15 would be $5.45 per gallon and is 15 extra miles away" << endl;
    string PaD;
    float fPaD;
    cin >> PaD;
    while(PaD!="0,0"){
        c.split_c(PaD);
        cin >> PaD;
    }
    c.process();
    return 0;
}
