#include <bits/stdc++.h>

using namespace std;
int v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,n,i,m,j,k,mx,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        sort(v+1,v+n+1);
        int mx=v[2]-v[1];
        for(i=1;i<n;++i)
        {
            mx=min(mx,v[i+1]-v[i]);
        }
        cout<<mx<<'\n';
    }
    return 0;
}