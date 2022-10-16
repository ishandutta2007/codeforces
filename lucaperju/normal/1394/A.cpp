#include <bits/stdc++.h>
using namespace std;
long long v[100005];
long long sp[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,m,d,i,j,t;
    cin>>n>>d>>m;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
    }
    sort(v+1,v+n+1);
    long long s=0,pz;
    for(pz=1;pz<=n;++pz)
    {
        if(v[pz]>m)
            break;
    }
    for(i=1;i<=n;++i)
    {
        sp[i]=sp[i-1]+v[i];
    }
    if(pz==n+1)
    {
        cout<<sp[n];
        return 0;
    }
    long long sc=0;
    long long mx=0;
    for(i=n;i>=pz;--i)
    {
        sc+=v[i];
        int cattrb=(n-i)*d;
        cattrb-=(i-pz);
        cattrb=max(cattrb,0);
        if(cattrb>=pz)
            break;
        else mx=max(mx,sc+sp[pz-1]-sp[cattrb]);
    }
    cout<<mx;
    return 0;
}