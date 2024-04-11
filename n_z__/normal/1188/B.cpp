#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int>mp;
main()
{
    int n,p,k;
    cin>>n>>p>>k;
    int ans=0;
    for(int x=1;x<=n;x++)
    {
        int y;
        cin>>y;
        int q=((y*y%p*y%p*y%p-k*y%p)%p+p)%p;
        ans+=mp[q];
        mp[q]++;
    }
    cout<<ans<<endl;
}