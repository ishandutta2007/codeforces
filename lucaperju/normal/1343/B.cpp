#include <bits/stdc++.h>
using namespace std;
long long v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long mxc=0,m,i,j=0,t,x,z,y,n,k;
    long long s=0,mx=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%4==2)
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(i=1;i<=n/2;++i)
            cout<<i*2<<' ';
        for(i=1;i<n/2;++i)
            cout<<i*2-1<<' ';
        cout<<n+(n/2-1);
        cout<<'\n';
    }
    return 0;
}