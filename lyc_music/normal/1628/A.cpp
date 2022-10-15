// Lynkcat.
// Problem: A. Meximum Array
// URL: https://codeforces.com/contest/1628/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// -----------------------------------------------

//~~
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
deque<int> G[N];
int n,a[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		G[a[i]].push_back(i);
	}
	poly now;
	for (int i=0;i<=n;i++)
		if (G[i].size())
		now.push_back(i);
		else break;
	poly ans;
	int tot=n;
	int nowmn=0;
	while (!now.empty())
	{
		int mn=0;
		for (auto u:now)
			mn=max(mn,G[u][0]);
		nowmn=max(nowmn,mn);
		for (auto u:now)
			while (!G[u].empty()&&G[u][0]<=mn)
			{
				// cout<<"!"<<u<<" "<<G[u][0]<<" "<<mn<<endl;
				tot--;
				G[u].pop_front();
			}
		ans.push_back(now.size());
		poly nxt;
		for (auto u:now)
		{
			// cout<<u<<","<<G[u].size()<<" "<<mn<<endl;
			if (G[u].size()) nxt.push_back(u);
			else break;
		}
		swap(nxt,now);
	}
	for (int i=0;i<=n;i++) 
			while (!G[i].empty()&&G[i][0]<=nowmn)
			{
				tot--;
				G[i].pop_front();
			}
	// cout<<tot<<endl;
	while (tot--) ans.push_back(0);
	cout<<ans.size()<<endl;
	for (auto u:ans) cout<<u<<" ";
	cout<<endl;
	for (int i=0;i<=n;i++)  G[i].clear();
}
signed main()
{
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}