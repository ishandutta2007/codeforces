#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
	int n,k;
    cin>>n>>k;
    if(n*(n+1)/2>k)cout<<-1<<endl;
    else if((n*(n+1)/2-((n+1)/2)*((n+1)/2+1)/2)*2+(n%2)*((n+1)/2)<=k){cout<<(n*(n+1)/2-((n+1)/2)*((n+1)/2+1)/2)*2+(n%2)*((n+1)/2)<<endl;
        for(int x=1;x<=n;x++)
        cout<<x<<' ';
        cout<<endl;for(int x=n;x>=1;x--)cout<<x<<' ';}
    else{
        int ans=n*(n+1)/2;
        int l=1,r=n;
        for(int x=1;x<=n;x++)
        if(ans-x+max(x,r)<=k)r--,ans=ans-x+max(x,r+1);
        else l++;
        l=1,r=n;
        cout<<ans<<endl;
        for(int x=1;x<=n;x++)
        cout<<x<<' ';
        cout<<endl;
        ans=n*(n+1)/2;
        for(int x=1;x<=n;x++)
        if(ans-x+max(x,r)<=k)r--,ans=ans-x+max(x,r+1),cout<<r+1<<' ';
        else l++,cout<<l-1<<' ';
    }
}