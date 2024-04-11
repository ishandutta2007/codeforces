#include <bits/stdc++.h>
using namespace std;
long long v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long i,j,n,t,m,k,n1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        long long rz=0;
        for(i=1;i<=n;i+=2)
            rz+=v[i];
        long long sc=0;
        long long mxc=0;
        for(i=2;i<=n;i+=2)
        {
            sc+=v[i]-v[i-1];
            sc=max(sc,0LL);
            mxc=max(sc,mxc);
        }
        sc=0;
        for(i=2;i+1<=n;i+=2)
        {
            sc+=v[i]-v[i+1];
            sc=max(sc,0LL);
            mxc=max(sc,mxc);
        }
        cout<<rz+mxc<<'\n';
    }
    return 0;
}