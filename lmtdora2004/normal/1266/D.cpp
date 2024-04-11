#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
int need[100005];
int want[100005];
vector<pair<int, pair<int, int> > > ans;

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1; i<=m; i++)
	{
		int u, v, val;
		cin>>u>>v>>val;
		need[u]+=val;
		want[v]+=val;
	}
	for(int u=1; u<=n; u++)
	{
		int ok=min(need[u], want[u]);
		need[u]-=ok;
		want[u]-=ok;
	}
	int it=1;
	for(int i=1; i<=n; i++)
	{
		while(need[i])
		{
			if(want[it])
			{
				int ok=min(need[i], want[it]);
				need[i]-=ok;
				want[it]-=ok;
				ans.push_back({i, {it, ok}});
			}
			else
			{
				it++;
			}
		}
	}
	cout<<ans.size()<<'\n';
	for(auto i:ans)
	{
		cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<'\n';
	}
}