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
//#define N
using namespace std;
int n;
poly G;
multiset<int>S;
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n*n;i++)
	{
		int x;
		cin>>x;
		S.insert(x);
	}
	while (!S.empty())
	{
		int now=(*(--S.end()));
		for (auto u:G)
		{
			S.erase(S.find(__gcd(now,u)));
			S.erase(S.find(__gcd(now,u)));
		}
		S.erase(S.find(now));
		G.push_back(now);
	}
	sort(G.begin(),G.end());
	for (auto u:G) cout<<u<<" ";
		
	
}
signed main()
{
	IOS;
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}