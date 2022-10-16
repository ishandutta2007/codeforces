#include <bits/stdc++.h>

using namespace std;
long long v[200005],dr[200005],st[200005];
int main()
{
    long long i,j=0,n,mx=-99999999999LL,k,cat=1,pz=-1,cur,x;
    cin>>n>>k>>x;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        st[i]=v[i]|st[i-1];
    }
    for(i=n;i>=1;--i)
        dr[i]=v[i]|dr[i+1];
    for(i=1;i<=k;++i)
        cat=cat*1LL*x;
    for(i=1;i<=n;++i)
    {
        cur=v[i]*1LL*cat;
        cur|=st[i-1];
        cur|=dr[i+1];
        mx=max(mx,cur);
    }
    cout<<mx;
}