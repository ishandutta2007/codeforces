// Problem: E. Doremy's Number Line
// Contest: Codeforces - Codeforces Global Round 24
// URL: https://codeforces.com/contest/1764/problem/E
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
#define N 100005
using namespace std;
int n,m,a[N],b[N],p[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	multiset<pa>S;
	multiset<int>S1;
	for (int i=2;i<=n;i++) p[i]=i;
	sort(p+2,p+n+1,[&](int x,int y)
	{
		return a[x]+b[x]>a[y]+b[y];
	});
	if (m<=a[1]) return cout<<"YES\n",void();
	if (m-b[1]>a[1]) return cout<<"NO\n",void();
	m-=b[1];
	int l=2;
	while (1)
	{
		while (l<=n&&a[p[l]]+b[p[l]]>=m)
		{
			S.insert(mp(a[p[l]],p[l]));
			l++;
		}
		if (S.empty()) return cout<<"NO\n",void();
		if ((*S.rbegin()).fi>=m)
			return cout<<"YES\n",void();
		int o=(*S.begin()).se;
		S.erase(mp(a[o],o));
		m-=b[o];
	}
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