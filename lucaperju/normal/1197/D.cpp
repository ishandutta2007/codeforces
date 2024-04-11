#include <bits/stdc++.h>

using namespace std;
int v[300005];
long long sp[300005],d[300005];
int main()
{
    long long i,j,n,m,k=0,cnt=0,s=0,mx=-9999999999LL,mn=9999999999LL,t;
    cin>>n>>m>>k;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        sp[i]=v[i]+sp[i-1];
    }
    for(i=1;i<=n;++i)
        for(j=i-1;j>=max(0LL,i-m);--j)
            d[i]=max(d[i],sp[i]-sp[j]+d[j]-k);
    for(i=1;i<=n;++i)
        mx=max(mx,d[i]);
    cout<<mx;
    return 0;
}