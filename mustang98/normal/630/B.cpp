#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;


int main()
{
    double n,res=1,t=1.000000011;
    ll st;
    cin>>n>>st;
    //for(int i=0;i<s;i++) n*=1.000000011;
    while(st>1)
    {
        if(st%2==0)
        {
            st/=2;
            t*=t;
        }
        else
        {
            res*=t;
            st--;
        }
    }
    t*=res;
    cout.precision(100);
    if (st) n*=t;
    cout<<n;
    return 0;
}