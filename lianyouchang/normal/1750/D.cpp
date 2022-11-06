// Problem: D. Count GCD
// Contest: Codeforces - CodeTON Round 3 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1750/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
int n,m,a[N];
inline int calc(int x,int m)
{
	// cout<<"calc "<<x<<endl;
	poly g;
	for (int i=2;i*i<=x;i++)
		if (x%i==0)
		{
			g.push_back(i);
			while (x%i==0) x/=i;
		}
	// cout<<"calc "<<x<<endl;
	if (x!=1) g.push_back(x);
	int ans=0;
	for (int i=0;i<(1<<g.size());i++)
	{
		int now=1;
		for (int j=0;j<g.size();j++)
			if ((i>>j)&1) now=now*g[j];
		if (__builtin_popcount(i)%2==0) ans=(ans+(m/now)%mod)%mod;
		else ans=(ans-(m/now)%mod+mod)%mod;
	}
	// cout<<"??"<<ans<<'\n';
	return ans;
}
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	int ans=1;
	for (int i=2;i<=n;i++)
	{
		if (a[i-1]%a[i]!=0) return cout<<"0\n",void();
		if (a[i]==a[i-1])
		{
			ans=(ans*(m/a[i])%mod)%mod;
		}
		else
		{
			int x=a[i-1]/a[i];
			ans=(ans*calc(x,m/a[i])%mod)%mod;
		}
	}
	cout<<ans<<'\n';
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}