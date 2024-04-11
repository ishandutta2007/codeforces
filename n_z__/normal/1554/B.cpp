#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200001];
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int x=1;x<=n;x++)
        cin>>a[x];
        int ans=-10000000;
        for(int x=n;x>=1;x--)
        for(int y=x-1;y>=1;y--)
        if(x*y<ans){y=0;break;}
        else ans=max(ans,x*y-k*(a[x]|a[y]));
        cout<<ans<<endl;
    }
}