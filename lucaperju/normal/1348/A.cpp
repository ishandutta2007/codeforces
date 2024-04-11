#include <bits/stdc++.h>
using namespace std;
int v[10004];
int rz[10004];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,i,j,m,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long s=0;
        s=(1<<n);
        for(i=1;i<=n/2-1;++i)
            s+=(1<<i);
        for(i=n/2;i<n;++i)
            s-=(1<<i);
        cout<<s<<'\n';
    }
    return 0;
}