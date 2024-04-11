#include<bits/stdc++.h>
 
using namespace std;
#define int long long
vector <int> index;
vector <vector <pair <int, int> > > g;
int n, q, s;
void go_to_ind(int v, int l, int r)
{
	if(l == r)
	{
		index[l] = v;
		return;
	}
		go_to_ind(v * 2, l, (r + l) / 2);
		go_to_ind(v * 2 + 1, (r + l) / 2 + 1, r);
}
void build(int v, int l, int r)
{
	if(l == r)
	{
		g[v].push_back({v + 4 * n, 0});
		g[v + 4 * n].push_back({v, 0});
		return;
	}
	g[v].push_back({v * 2, 0});
	g[v].push_back({v * 2 + 1, 0});
	int len1 = ((r + l) / 2 - l + 1);
	int len2 = r - (r + l) / 2;
	g[v * 2 + 4 * n].push_back({v + 4 * n, 0});
	g[v * 2 + 1 + 4 * n].push_back({v + 4 * n, 0});
	build(v * 2, l, (r + l) / 2);
	build(v * 2 + 1, (r + l) / 2 + 1, r);
}
vector <int> vec;
void go_to_ind1(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		vec.push_back(v);
	}
	else if(l <= ar && r >= al)
	{
		go_to_ind1(v * 2, l, (r + l) / 2, al, ar);
		go_to_ind1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
	}
}
signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	cin >> n >> q >> s;
	s--;
	g.resize(n * 8);
	index.resize(n);
	build(1, 0, n - 1);
	go_to_ind(1, 0, n - 1);
	while(q--)
	{
		int t;
		cin >> t;
		if(t == 1)
		{
			int v, u, w;
			cin >> v >> u >> w;
			v--;
			u--;
			g[index[v]].push_back({index[u], w});
		}
		else if(t == 2)
		{
			int v, l, r, w;
			cin >> v >> l >> r >> w;
			l--;
			r--;
			v--;
			go_to_ind1(1, 0, n - 1, l, r);
			for(int i = 0; i < vec.size(); i++)
			{
				g[index[v]].push_back({vec[i], w});
			}
			vec.clear();
		}
		else
		{
			int v, l, r, w;
			cin >> v >> l >> r >> w;
			l--;
			r--;
			v--;
			go_to_ind1(1, 0, n - 1, l, r);
			for(int i = 0; i < vec.size(); i++)
			{
				g[vec[i] + 4 * n].push_back({index[v] + 4 * n, w});
			}
			vec.clear();
		}
	}
	vector <int> dist(8 * n, 1e18);
	s = index[s];
	dist[s] = 0;
	set <pair <int, int> > st;
	st.insert({0, s});
	while(st.size() != 0)
	{
		int v = st.begin() -> second;
		st.erase(st.begin());
		for(int i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i].first;
			int wei = g[v][i].second;
			if(wei + dist[v] < dist[to])
			{
				st.erase({dist[to], to});
				dist[to] = dist[v] + wei;
				st.insert({dist[to], to});
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(dist[index[i]] == 1e18)
		{
			cout << -1 << " ";
		}
		else
		{
			cout << dist[index[i]] << " ";
		}
	}
	return 0;
}