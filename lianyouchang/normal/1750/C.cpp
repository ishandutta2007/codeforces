// Problem: C. Complementary XOR
// Contest: Codeforces - CodeTON Round 3 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1750/problem/C
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
int n,a[N],b[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		a[i]=ch-'0';
	}
	for (int i=n;i>=1;i--) 
		a[i]^=a[i-1];
	for (int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		b[i]=ch-'0';
	}
	for (int i=n;i>=1;i--) 
		b[i]^=b[i-1];
	for (int i=2;i<=n;i++)
	{
		if (a[i]!=b[i]) return cout<<"NO\n",void();
	}
	
	vector<pa>ans;
	cout<<"YES\n";
	if (b[1])
	{
		ans.push_back(mp(2,n));
		b[1]^=1;
		a[2]^=1,b[2]^=1;
	}
	for (int i=2;i<=n;i++)
		if (a[i])
		{
		ans.push_back(mp(1,i-1));
			a[1]^=1;
		}
	if (a[1]) ans.push_back(mp(1,n));
	cout<<ans.size()<<'\n';
	for (auto u:ans) cout<<u.fi<<" "<<u.se<<'\n';

	
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