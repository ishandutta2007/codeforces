#include <bits/stdc++.h>

using namespace std;
long long v[200005],fv[200005];
int main()
{
    long long t,n,i,j,mn=100003LL*100003LL,k,a,b,mx=0,tot,m,obj,st,cntp=0,cnti=0,s=0,pz;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        ++fv[v[i]];
        if(fv[v[i]]>mx)
        {
            mx=fv[v[i]];
            pz=v[i];
        }
    }
    cout<<n-mx<<'\n';
    for(i=1;i<n;++i)
        if(v[i]==pz)
            break;
    int poz=i;
    for(;i>=1;--i)
    {
        if(v[i]!=pz)
        {
            if(v[i]>pz)
            {
                cout<<2<<' '<<i<<' '<<i+1<<'\n';
            }
            else
            {
                cout<<1<<' '<<i<<' '<<i+1<<'\n';
            }
        }
    }
    for(i=poz+1;i<=n;++i)
    {
        if(v[i]!=pz)
        {
            if(v[i]>pz)
                cout<<2<<' '<<i<<' '<<i-1<<'\n';
            else
                cout<<1<<' '<<i<<' '<<i-1<<'\n';
        }
    }
    return 0;
}