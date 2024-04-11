#include <bits/stdc++.h>

using namespace std;
int v[200005],fv[200005];
int main()
{
    long long t,n,i,j,mn=100003LL*100003LL,k,a,b,mx=0,tot,m,obj,st,cntp=0,cnti=0,s=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        ++fv[v[i]];
        if(fv[v[i]]==3)
        {
            cout<<"NO";
            return 0;
        }
        if(fv[v[i]]==2)
            ++s;
    }
    cout<<"YES\n";
    sort(v+1,v+n+1);
    cout<<s<<'\n';
    for(i=1;i<=n;++i)
    {
        if(fv[v[i]]==2)
        {
            --fv[v[i]];
            cout<<v[i]<<' ';
        }
    }
    cout<<'\n';
    cout<<n-s<<'\n';
    for(i=n;i>=1;--i)
    {
        if(fv[v[i]]==1)
        {
            --fv[v[i]];
            cout<<v[i]<<' ';
        }
    }
    return 0;
}