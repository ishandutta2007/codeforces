//Author:Magic_Moon

#include<bits/stdc++.h>
#define int long long
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define down(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
using namespace std;
int n,k,l;
string s;
const int maxn=1e6+10;
int a[maxn];
int f[maxn],dp[maxn];
int check(int x)
{
	up(i,1,n)
	{
		f[i]=f[i-1]+a[i];
		dp[i]=dp[i-1];
		if(f[max(i-l,0ll)]+x<f[i])
		{
			f[i]=f[max(i-l,0ll)]+x;
			dp[i]=dp[max(i-l,0ll)]+1;
		}
	}
	return dp[n]<=k;
}
int solve()
{
	int L=0,R=l;
	int ans;
	while(L<=R)
	{
		int mid=(L+R)>>1;
		if(check(mid))
		{
			R=mid-1;
			ans=mid;
		}
		else L=mid+1;
	}
	int ze=check(ans);
	return f[n]-ans*k;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k>>l>>s;
	up(i,1,n)
	{
		a[i]=(s[i-1]>='a');
	}
	int ans=0;
	ans=solve();
	up(i,1,n)a[i]^=1;
	ans=min(ans,solve());
	cout<<ans;
	
}