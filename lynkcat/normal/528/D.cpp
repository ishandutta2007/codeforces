// Lynkcat.
// Problem: B. Fuzzy Search
// Contest: Codeforces - 10.9(1)
// URL: https://codeforces.com/gym/403085/problem/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
// #define int ll
// #define N 
using namespace std;
bitset<200005>f,g;
int n,m,q;
string s,t;
void BellaKira()
{
	cin>>n>>m>>q;
	cin>>s>>t;
	s=' '+s,t=' '+t;
	f.set();
	int lst=0;
	
	g.reset();
	lst=0;
	for (int i=1;i<=n;i++)
		if (s[i]=='A')
		{
			int l=i-q,r=i+q;
			l=max(l,lst+1),r=min(r,n);
			for (int j=l;j<=r;j++) g[j]=1;
			lst=r;
		}
	for (int i=1;i<=m;i++)
		if (t[i]=='A') 
		{
			f&=(g>>(i-1));
		}
	
	g.reset();
	lst=0;
	for (int i=1;i<=n;i++)
		if (s[i]=='C')
		{
			int l=i-q,r=i+q;
			l=max(l,lst+1),r=min(r,n);
			for (int j=l;j<=r;j++) g[j]=1;
			lst=r;
		}
	for (int i=1;i<=m;i++)
		if (t[i]=='C') f&=(g>>(i-1));
		
	g.reset();
	lst=0;
	for (int i=1;i<=n;i++)
		if (s[i]=='G')
		{
			int l=i-q,r=i+q;
			l=max(l,lst+1),r=min(r,n);
			for (int j=l;j<=r;j++) g[j]=1;
			lst=r;
		}
	for (int i=1;i<=m;i++)
		if (t[i]=='G') f&=(g>>(i-1));
		
	g.reset();
	lst=0;
	for (int i=1;i<=n;i++)
		if (s[i]=='T')
		{
			int l=i-q,r=i+q;
			l=max(l,lst+1),r=min(r,n);
			for (int j=l;j<=r;j++) g[j]=1;
			lst=r;
		}
	for (int i=1;i<=m;i++)
		if (t[i]=='T') f&=(g>>(i-1));
	
	int ans=0;
	for (int i=1;i<=n;i++) 
	{
		ans+=f[i];
		// cout<<f[i];
	}
	// cout<<'\n';
	cout<<ans<<'\n';
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}