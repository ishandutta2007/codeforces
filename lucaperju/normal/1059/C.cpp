#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    int n,put=1,i;
    cin>>n;
    while(n)
    {
        if(n==1)
        {
            cout<<put;
            return 0;
        }
        else
        if(n==2)
        {
            cout<<put<<' '<<put*2;
            return 0;
        }
        else
        if(n==3)
        {
            cout<<put<<' '<<put<<' '<<put*3;
            return 0;
        }
        for(i=1;i<=(n+1)/2;++i)
            cout<<put<<' ';
        put*=2;
        n/=2;
    }
}