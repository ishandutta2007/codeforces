#include<bits/stdc++.h>
 
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		vector <vector <int> > g(20);
		vector <vector <int> > g1(20);
		vector <int> reach1(20);
		vector <bool> used(20);
		for(int i = 0; i < a.size(); i++)
		{
			if(a[i] == b[i])
			{
				continue;
			}
			g1[a[i] - 'a'].push_back(b[i] - 'a');
			g1[b[i] - 'a'].push_back(a[i] - 'a');
			g[a[i] - 'a'].push_back(b[i] - 'a');
			if(a[i] != b[i])
			{
				reach1[a[i] - 'a'] |= (1 << (b[i] - 'a'));
			}
		}
		for(int i = 0; i < n; i++)
		{
			used[a[i] - 'a'] = 1;
			used[b[i] - 'a'] = 1;
		}
		vector <int> dp((1 << 20));
		for(int i = 0; i < 20; i++)
		{
			dp[(1 << i)] = 1; 
		}
		int maxd = 0;
		for(int mask = 1; mask < (1 << 20); mask++)
		{
			int cnt1 = 0;
			for(int j = 0; j < 20; j++)
			{
				if((1 << j) & mask)
				{
					cnt1++;
					dp[mask] |= (dp[mask ^ (1 << j)] & ((reach1[j] & mask) == 0));
				}
			}
			if(dp[mask])
			{
				maxd = max(maxd, cnt1);
			}
		}
		int check = 0;
		for(int i = 0; i < 20; i++)
		{
			if(!used[i])
			{
				check ++;
			}
		}
		vector <bool> used1(20);
		int c1 = 0;
		for(int i = 0; i < 20; i++)
		{
			if(!used1[i] && used[i])
			{
				queue <int> q;
				q.push(i);
				used1[i] = 1;
				c1++;
				while(q.size() != 0)
				{
					int v = q.front();
					q.pop();
					for(int j = 0; j < g1[v].size(); j++)
					{
						int to = g1[v][j];
						if(!used1[to])
						{
							q.push(to);
							used1[to] = 1;
						}
					}
				}
			}
		}
		cout << 2 * 20 - c1 - maxd - check << "\n";
	}
	return 0;
}