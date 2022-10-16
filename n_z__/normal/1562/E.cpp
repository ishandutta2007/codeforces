#include<bits/stdc++.h>
using namespace std;
#define int long long
int lcp[8001][8001],dp[8001];
main()
{
    int t;
	cin>>t;
	while(t--)
	{
        int n;
        string s;
        cin>>n>>s;
        s=" "+s;
		int ans=0;
		for(int x=n;x;x--)
		for(int y=n;y;y--)
		lcp[x][y]=(s[x]==s[y])*(lcp[x+1][y+1]+1);
        dp[1]=n;
		for(int x=1;x<=n;ans=max(ans,dp[x]),x++,dp[x]=n+1-x)
		for(int y=1;y<x;dp[x]=max(dp[x],(s[y+lcp[x][y]]<s[x+lcp[x][y]])*(dp[y]+n+1-x-lcp[x][y])),y++);
		cout<<ans<<endl;
	}
}