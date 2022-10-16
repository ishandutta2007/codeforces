#include <bits/stdc++.h>
using namespace std;
int v[200005],d[2005],sp[2005],best[2005];
int main()
{
    ios_base::sync_with_stdio(0);
    long long p,add=1,t,h,i,j,n,mn=99999,k=0,mx=-999999999999LL,tot,m,obj,cnt=0,cnti=0,s=0,nri=0,b2,a3,b3;
    int a,b;
    cin>>n>>m>>k;
    for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    n=k;
    for(i=1;i<=n/2;++i)
        swap(v[i],v[n-i+1]);
    for(i=1;i<=m;++i)
    {
        cin>>a>>b;
        if(a<=n)
            best[a]=max(best[a],b);
    }
    for(i=1;i<=n;++i)
        sp[i]=sp[i-1]+v[i];
    for(i=1;i<=n;++i)
    {
        d[i]=v[i]+d[i-1];
        for(j=1;j<=i;++j)
            if(best[j])
                d[i]=min(d[i],d[i-j]+sp[i-best[j]]-sp[i-j]);
    }
    cout<<d[n];
    return 0;
}