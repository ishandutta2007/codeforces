#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n+1),ida(n+1),mi(n+1),ma(n+1);
        for(int x=1;x<=n;x++)
        cin>>a[x],ida[a[x]]=x;
        mi[0]=ma[0]=ida[0];
        for(int x=1;x<n;x++)
        mi[x]=min(mi[x-1],ida[x]),ma[x]=max(ma[x-1],ida[x]);
        int ans=0;
        for(int l=1;l<=n;l++)
        ans+=max(-max(1ll,ma[(l-1)/2]-l+1)+min(mi[(l-1)/2],n-l+1)+1,0ll);
        cout<<ans<<endl;
    }
}