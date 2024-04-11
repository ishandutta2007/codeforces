#include<bits/stdc++.h>
using namespace std;
vector <vector <int> > g;
 
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	vector <int> deep;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		g.resize(n);
		for(int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			g[b].push_back(a);
		}
		deep.resize(n);
		vector <int> ans;
		for(int i = 0; i < n; i++)
		{
			deep[i] = 0;
			for(int j = 0; j < g[i].size(); j++)
			{
				int to = g[i][j];
				deep[i] = max(deep[i], deep[to] + 1);
			}
			if(deep[i] > 1)
			{
				ans.push_back(i);
				deep[i] = -1;
			}
			g[i].clear();
		}
		cout << ans.size() << "\n";
		for(int i = 0; i < ans.size(); i++){
			cout << ans[i] + 1 << " ";
		}
		cout << "\n";
	}
	return 0;
}