#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <vector <pair <int, int> > > g;
vector <int> val;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int s, t;
	cin >> s >> t;
	s--;
	t--;
	val.resize(n);
	g.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> val[i];
	}
	for(int i = 0; i < m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		a--;
		b--;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}
	vector <int> dist1(n, 1e18);
	dist1[s] = 0;
	set <pair <int, int> > st;
	st.insert({0, s});
	vector <vector <int> > vec1(n + 1), vec2(n + 1);
	int now = 1;
	int p = 0;
	while(st.size() != 0)
	{
		int v = st.begin() -> second;
		st.erase(st.begin());
		if(p != dist1[v])
		{
			now++;
		}
		vec1[now].push_back(v);
		p = dist1[v];
		for(int i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i].first;
			int w = g[v][i].second;
			if(dist1[v] + w < dist1[to])
			{
				st.erase({dist1[to], to});
				dist1[to] = dist1[v] + w;
				st.insert({dist1[to], to});
			}
		}
	}
	vector <int> dist2(n, 1e18);
	dist2[t] = 0;
	st.insert({0, t});
	p = 0;
	now = 1;
	while(st.size() != 0)
	{
		int v = st.begin() -> second;
		st.erase(st.begin());
		if(p != dist2[v])
		{
			now++;
		}
		vec2[now].push_back(v);
		p = dist2[v];
		for(int i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i].first;
			int w = g[v][i].second;
			if(dist2[v] + w < dist2[to])
			{
				st.erase({dist2[to], to});
				dist2[to] = dist2[v] + w;
				st.insert({dist2[to], to});
			}
		}
	}
	vector <vector <int> > sum(n + 1, vector <int> (n + 1)), tot(n + 1, vector <int> (n + 1));
	vector <bool> used(n);
	for(int i = 0; i <= n; i++)
	{
		if(i)
		{
			sum[i][0] = sum[i - 1][0];
			tot[i][0] = tot[i - 1][0];
			for(int j = 0; j < vec1[i].size(); j++)
			{
				sum[i][0] += val[vec1[i][j]];
				tot[i][0]++;
				used[vec1[i][j]] = 1;
			}
		}
		for(int j = 1; j <= n; j++)
		{
			sum[i][j] = sum[i][j - 1];
			tot[i][j] = tot[i][j - 1];
			for(int k = 0; k < vec2[j].size(); k++)
			{
				if(!used[vec2[j][k]])
				{
					sum[i][j] += val[vec2[j][k]];
					tot[i][j]++;
				}
			}
		}
	}
	vector <vector <int> > fa(n + 1, vector <int> (n + 1)), fb(n + 1, vector <int> (n + 1));
	vector <vector <int> > ga(n + 1, vector <int> (n + 1)), gb(n + 1, vector <int> (n + 1));
	int all = sum[n][n];
	for(int i = n; i >= 0; i--)
	{
		for(int j = n; j >= 0; j--)
		{
			if(tot[i][j] < n)
			{
				int s = all - sum[i][j];
				int cntt = tot[i][j];
				fa[i][j] = s - gb[cntt + 1][j];
				fb[i][j] = s - ga[i][cntt + 1];
				ga[i][cntt] = min(min(ga[i][cntt], ga[i][cntt + 1]), fa[i][j]);
				gb[cntt][j] = min(min(gb[cntt][j], gb[cntt + 1][j]), fb[i][j]);
			}
		}
	}
	int A = fa[0][0];
	int B = all - fa[0][0];
	if(A > B)
	{
		cout << "Break a heart";
	}
	else if(A == B)
	{
		cout << "Flowers";
	}
	else
	{
		cout << "Cry";
	}
	return 0; 
}