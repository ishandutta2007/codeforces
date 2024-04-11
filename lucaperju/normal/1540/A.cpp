#include <bits/stdc++.h>
using namespace std;
int v[100003];
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,a,k,x,b,i,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        sort(v+1,v+n+1);
        long long ans=0;
        for(i=1;i<n;++i)
        {
            ans=ans-(v[i+1]-v[i])*1LL*((n-i)*1LL*i-1);
        }
        cout<<ans<<'\n';
    }
    return 0;
}