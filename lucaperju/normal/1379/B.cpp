#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long m,i,j,x,y,k,t,l,r;
    cin>>t;
    while(t--)
    {
        cin>>l>>r>>m;
        if(m<=l)
        {
            cout<<l<<' '<<l<<' '<<l*2LL-m<<'\n';
            continue;
        }
        for(long long a=l;a<=r;++a)
        {
            long long rest=m%a;
            if(rest<=r-l)
            {
                cout<<a<<' '<<l+rest<<' '<<l<<'\n';
                break;
            }
            rest=a-rest;
            if(rest<=r-l)
            {
                cout<<a<<' '<<l<<' '<<l+rest<<'\n';
                break;
            }
        }
    }
    return 0;
}