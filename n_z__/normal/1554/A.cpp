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
        int n;
        cin>>n;
        int ans=0;
        for(int x=1;x<=n;x++)
        cin>>a[x],ans=max(ans,a[x]*a[x-1]);
        cout<<ans<<endl;
    }
}