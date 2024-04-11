#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main()
{    
    int q;
    cin>> q;
    for (int i=0; i<q;i++)
    {
        int a,b;
        long long n;
        cin>> n >> a >> b;
        cout << (n/2)*min(2*a, b)+ (n%2)*a << endl;
        
        
        
        
        
        
        
    }
    
    
    
    
    
    
    
    
    
    return 0;
}