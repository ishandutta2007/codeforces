#include <bits/stdc++.h>

using namespace std;
int v[100005];
int main()
{
    long long i,j,n,m,b,k,s;
    cin>>n>>m>>k;
    for(i=1;i<=n;++i)
        cin>>v[i];
    s=v[n]-v[1]+1;
    for(i=1;i<=n;++i)
        v[i]=v[i+1]-v[i]-1;
    --n;
    --k;
    sort(v+1,v+n+1);
    for(i=n;i>=1 && k;--i)
    {
        s-=v[i];
        --k;
    }
    cout<<s;
}