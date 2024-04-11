#include<bits/stdc++.h>
 
using namespace std;
#define int long long
int n, q, W;
int N = 2e5 + 10;
int timer = 0;
vector <vector <pair <int, int> > > g;
vector <int> in, out, ind, d, pred;
struct edge{
	int x, y, w;
	edge(int x, int y, int w):
		x(x),
		y(y),
		w(w){}
};
vector <edge> edges;
struct node{
	int m, val, lm, mr, lmr, tag;
	node friend operator+(node a, node b)
	{
		node c;
		c.m = max(a.m, b.m);
		c.val = max(a.val, b.val);
		c.lm = max(max(a.lm, b.lm), a.val + b.m);
		c.mr = max(max(a.mr, b.mr), b.val + a.m);
		c.lmr = max(max(a.lmr, b.lmr), max(a.val + b.mr, b.val + a.lm));
		c.tag =0;
		return c;
	}
};
vector <node> T;
void dfs(int v)
{
	ind[++timer] = v;
	in[v] = out[v] = timer;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		if(to == pred[v])
		{
			continue;
		}
		pred[to] = v;
		d[to] = d[v] + g[v][i].second;
		dfs(to);
		ind[++timer] = v;
		out[v] = timer;
	}
}
void build(int v, int l, int r)
{
	if(l == r)
	{
		T[v] = (node){-2 * d[ind[l]], d[ind[l]], -d[ind[l]], -d[ind[l]], 0, 0};
		return ;
	}
	int midd = (r + l) / 2;
	build(v * 2, l, ( r+ l) / 2);
	build(v * 2 + 1, (r + l) / 2 + 1, r);
	T[v] = T[v * 2] + T[v * 2 + 1]; 
}
void doit(int v, int w)
{
	T[v].m += -2 * w;
	T[v].val += w;
	T[v].lm -= w;
	T[v].mr -= w;
	T[v].tag += w;
}
void push(int v)
{
	if(T[v].tag == 0)return;
	doit(v * 2, T[v].tag);
	doit(v * 2 + 1, T[v].tag);
	T[v].tag = 0;
}
void modify(int v, int l, int r, int al, int ar, int w)
{
	if(al <= l && ar >= r)
	{
		doit(v, w);
		return;
	}
	if(l != r)
	{
	push(v);
	}
	int midd = l + r >> 1;
	if(al <= midd)
	{
		modify(v * 2, l, midd, al, ar, w);
	}
	if(ar > midd)
	{
		modify(v * 2 + 1, midd + 1, r, al, ar, w);
	}
	if(l != r)
	{
		T[v] = T[v * 2] + T[v * 2 + 1];
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> q >> W;
	g.resize(N);
	in.resize(N);
	out.resize(N);
	ind.resize(N);
	d.resize(N);
	T.resize(N << 2);
	pred.resize(N);
	for(int i = 0; i < n - 1; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		g[x].push_back({y, w});
		g[y].push_back({x, w});
		edges.push_back(edge(x, y, w));
	}
	dfs(1);
	build(1, 1, timer);
	int last = 0;
	while(q--)
	{
		int d, e;
		cin >> d >> e;
		d = (d + last) % (n -1);
		e = (e + last) % W;
		int x = edges[d].x;
		int y = edges[d].y;
		if(pred[y] == x)
		{
			swap(x, y);
		}
		modify(1, 1, timer, in[x], out[x], e - edges[d].w);
		edges[d].w = e;
		last = T[1].lmr;
		cout << last << "\n";
	}
	return 0;
}