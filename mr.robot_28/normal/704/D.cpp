#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const double eps = 1e-13;
struct edge{
	int a, b;
	int cap, flow;
	edge(int a, int b, int cap):
		a(a),
		b(b),
		cap(cap),
		flow(0){};
	int other(int v)
	{
		return (b == v) ? a : b;
	}
	int capTo(int v)
	{
		return (v == b) ? cap - flow : flow;
	}
	void addFlow(int v, int delta)
	{
		if(v == b)
		{
			flow += delta;
		}
		else
		{
			flow -= delta;
		}
	}
};
vector <edge> edges;
int n, m;
vector <vector <int> > g;
vector <int> h, p;
vector <int> k;
vector <int> A;
vector <int> cntx, cnty;
bool bfs(int st, int end)
{
	vector <bool> used(h.size());
	queue <int> Q;
	for(int i = 0; i < h.size(); i++)
	{
		k[i] = h[i] = 0;
		p[i] = 0;
	}
	Q.push(st);
	used[st] = true;
	while(Q.size() != 0)
	{
		int v = Q.front();
		Q.pop();
		if(v == end)
		{
			return 1;
		}
		for(int i = 0; i < g[v].size(); i++)
		{
			int e = g[v][i];
			int to = edges[e].other(v);
			if(!used[to] && edges[e].capTo(to))
			{
				used[to] = true;
				h[to] = h[v] + 1;
				p[to] = e;
				Q.push(to);
			}
		}
	}
	return 0;
}
bool dfs(int v, int end)
{
	if(v == end)
	{
		return 1;
	}
	for(; k[v] < g[v].size(); k[v]++)
	{
		int to = edges[g[v][k[v]]].other(v);
		if(h[to] == h[v] + 1 && edges[g[v][k[v]]].capTo(to) && dfs(to, end))
		{
			p[to] = g[v][k[v]];
			return 1;
		}
	}
	return 0;
}
int Dinic(int st, int end)
{
	int res = 0;
	while(bfs(st, end))
	{
		while(dfs(st, end))
		{
			int flow = 1e9;
			for(int i = end; i != st; i = edges[p[i]].other(i))
			{
				flow = min(flow, edges[p[i]].capTo(i));
			}
			for(int i = end; i != st; i = edges[p[i]].other(i))
			{
				edges[p[i]].addFlow(i, flow);
			}
			res += flow;
		}
	}
	return res;
}
signed main() {	
 //	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
  //cout.tie(NULL);
  	cin >> n >> m;
  	int r, b;
  	cin >> r >> b;
  	cntx.resize(n);
  	cnty.resize(n);
  	vector <pair <int, int> > x(n);
  	vector <int> uniqx, uniqy;
  	for(int i = 0; i < n; i++)
  	{
  		cin >> x[i].first >> x[i].second;
  		uniqx.push_back(x[i].first);
  		uniqy.push_back(x[i].second);
	}
	sort(uniqx.begin(), uniqx.end());
	sort(uniqy.begin(), uniqy.end());
	int tx = unique(uniqx.begin(), uniqx.end()) - uniqx.begin();
	int ty = unique(uniqy.begin(), uniqy.end()) - uniqy.begin();
	for(int i = 0; i < n; i++)
	{
		x[i].first = lower_bound(uniqx.begin(), uniqx.begin() + tx, x[i].first) - uniqx.begin();
		x[i].second = lower_bound(uniqy.begin(), uniqy.begin() + ty, x[i].second) - uniqy.begin();
		cntx[x[i].first]++;
		cnty[x[i].second]++;
	}
	vector <int> pmax(n, 1e9), pmin(n, 0);
	vector <int> pmax1(n, 1e9), pmin1(n, 0);
	for(int i = 0; i < m; i++)
	{
		int t, l, d;
		cin >> t >> l >> d;
		int ind;
		if(t == 1)
		{
			ind = lower_bound(uniqx.begin(), uniqx.begin() + tx, l) - uniqx.begin();
			if(ind == tx || uniqx[ind] != l || cntx[ind] <= d)
			{
				continue;
			}
			pmin[ind] = max(pmin[ind], (cntx[ind] - d + 1) / 2);
			pmax[ind] = min(pmax[ind], (cntx[ind] + d) / 2);
		}
		else
		{
			ind = lower_bound(uniqy.begin(), uniqy.begin() + ty, l) - uniqy.begin();
			if(ind == ty || uniqy[ind] != l || cnty[ind] <= d)
			{
				continue;
			}
			pmin1[ind] = max(pmin1[ind], (cnty[ind] - d + 1) / 2);
			pmax1[ind] = min(pmax1[ind], (cnty[ind] + d) / 2);
		}
	}
	int st1 = tx + ty;
	int end1 = tx + ty + 1;
	int st2 = end1 + 1;
	int end2 = st2 + 1;
	A.resize(end2 + 1);
	k.resize(end2 + 1);
	g.resize(end2 + 1);
	h.resize(end2 + 1);
	p.resize(end2 + 1);
	for(int i = 0; i < n; i++)
	{
		edges.push_back(edge(x[i].first, x[i].second + tx, 1));
		g[x[i].first].push_back(edges.size() - 1);
		g[x[i].second + tx].push_back(edges.size() - 1);
	}
	for(int i = 0; i < tx; i++)
	{
		if(pmin[i] > pmax[i])
		{
			cout << -1;
			return 0;
		}
		edges.push_back(edge(st1, i, pmax[i] - pmin[i]));
		g[st1].push_back(edges.size() - 1);
		g[i].push_back(edges.size() - 1);
		A[st1] -= pmin[i];
		A[i] += pmin[i]; 
	}
	for(int i = 0; i < ty; i++)
	{
		if(pmin1[i] > pmax1[i])
		{
			cout << -1;
			return 0;
		}
		edges.push_back(edge(i + tx, end1, pmax1[i] - pmin1[i]));
		g[i + tx].push_back(edges.size() - 1);
		g[end1].push_back(edges.size() - 1);
		A[i + tx] -= pmin1[i];
		A[end1] += pmin1[i];
	}
	for(int i = 0; i <= end1; i++)
	{
		if(A[i] > 0)
		{
			edges.push_back(edge(st2, i, A[i]));
			g[st2].push_back(edges.size() - 1);
			g[i].push_back(edges.size() -1);
		}
		else
		{
			edges.push_back(edge(i, end2, -A[i]));
			g[i].push_back(edges.size() - 1);
			g[end2].push_back(edges.size() - 1);
		}
	}
	edges.push_back(edge(end1, st1, 1e9));
	g[end1].push_back(edges.size() - 1);
	g[st1].push_back(edges.size() -1 );
	Dinic(st2, end2);
	for(int i = 0; i < g[end2].size(); i++)
	{
		if(edges[g[end2][i]].capTo(end2))
		{
			cout << -1;
			return 0;
		}
	}
	for(int i = 0; i < g[st2].size(); i++)
	{
		if(edges[g[st2][i]].capTo(edges[g[st2][i]].other(st2)))
		{
			cout << -1;
			return 0;
		}
	}
	int res = Dinic(st1, end1);
	cout << res * min(b, r) + max(b, r) * (n - res) << "\n";
	for(int i = 0; i < x.size(); i++)
	{
		if(edges[i].capTo(x[i].second + tx) ^ (r < b))
		{
			cout << "r";
		}
		else
		{
			cout << "b";
		}
	}
    return 0;
}