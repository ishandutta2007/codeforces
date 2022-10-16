#include <bits/stdc++.h>

using namespace std;
unsigned long long cat (unsigned long long n, unsigned long long p)
{
    unsigned long long cp=p,s=0;
    while(n>=p)
    {
        s=s+(long long)n/p;
        if(n/cp>=p)
            p=p*1LL*cp;
        else
            break;
    }
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    unsigned long long i,j=0,n,mn=(1LL<<62)-1+(1LL<<62),k=0,pz=-1,sc=0,x,y,z,a,b,c,m;
    cin>>n>>b;
    for(i=2LL;i*1LL*i<=b;++i)
    {
        if(b%i==0)
        {
            sc=0;
            while(b%i==0)
            {
                b/=i;
                ++sc;
            }
            mn=min(mn,(unsigned long long)cat(n,i)/sc);
        }
    }
    if(b!=1)
        mn=min(mn,cat(n,b));
    cout<<mn;
}