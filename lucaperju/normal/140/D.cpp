#include <bits/stdc++.h>
using namespace std;
int v[103];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,r1,r2,k=0,i,j;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    int sc=710;
    for(i=1;i<=n;++i)
    {
        if(v[i]<=sc)
            sc-=v[i],++k;
    }
    cout<<k<<' ';
    sc=350;
    for(i=1;i<=n && sc;++i)
    {
        if(v[i]<=sc)
            sc-=v[i],v[i]=0;
        else
        {
            v[i]-=sc;
            break;
        }
    }
    sc=0;
    for(i=1;i<=k;++i)
        v[i]+=v[i-1];
    for(i=1;i<=k;++i)
        sc+=v[i];
    cout<<sc;
    return 0;
}