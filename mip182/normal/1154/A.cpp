#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    long long a,b,c,d;
    cin >> a>>b>>c>>d;
    if (a==(a+b+c+d)/3)
    {
    cout << a-b << " "  << a-c << " "  <<a-d;
        return 0;
        
    }
    if (b==(a+b+c+d)/3)
    {
    cout << b-a <<  " "  << b-c << " "  <<b-d; 
            return 0;
    }
    if (c==(a+b+c+d)/3)
    {
    cout << c-b << " "  <<c-a << " "  <<c-d; 
            return 0;
    }
    if (d==(a+b+c+d)/3)
    {
    cout << d-b << " " << d-c <<" " <<d-a; 
            return 0;
    }
    
}