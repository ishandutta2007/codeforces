#include <bits/stdc++.h>
using namespace std;
#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ll long long
#define pii pair<int, int>
const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;
int n;
vec< vec< pii > > g;
const int NN = 21;
vec< int > p[NN], h, In, Out;
vec< ll > sum;
int TT = 0;

void dfs(int v, int par = -1, int H = 0, ll S = 0) 
{
	p[0][v] = par;
	h[v] = H;
	sum[v] = S;
	In[v] = TT ++;
	for(auto cur : g[v]) 
	{
		int to = cur.first;
		if(to == par) continue;
		int len = cur.second;
		dfs(to, v, H + 1, S + len);
	}
	Out[v] = TT ++;
}

int lca(int u, int v) 
{
	if(h[u] < h[v]) swap(u, v);
	for(int i = NN - 1; i >= 0; i --) 
	{
		int To = p[i][u];
		if(To == -1 || h[To] < h[v]) continue;
		u = To;
	}
	for(int i = NN - 1; i >= 0; i --) 
	{
		int X, Y;
		X = p[i][u];
		Y = p[i][v];
		if(X == -1 || Y == -1 || X == Y) continue;
		u = X;
		v = Y;
	}
	if(u != v) u = p[0][u];
	return u;
}

ll dist(int u, int v) 
{
	return sum[u] + sum[v] - 2ll * sum[lca(u, v)];
}
vec< int > fen;

void add(int pos, int val) 
{
	for(int cur = pos; cur < n + n; cur |= (cur + 1)) 
		fen[cur] += val;
}

int get(int pos) 
{
	int res = 0;
	for(int cur = pos; cur >= 0; cur = (cur & (cur + 1)) - 1) 
		res += fen[cur];
	return res;
}

int get(int l, int r) 
{
	if(l > r) return 0;
	else return get(r) - get(l - 1);  
}

set< int > Ve;
ll res = 0;

int get_Root() 
{
	if(Ve.empty()) return -1;
	int u = *Ve.begin();
	for(int i = NN - 1; i >= 0; i --) 
	{
		int pu = p[i][u];
		if(pu == -1 || get(In[pu], Out[pu]) == (int)Ve.size()) continue;
		u = pu;
	}
	if(get(In[u], Out[u]) < (int)Ve.size()) u = p[0][u];
	return u;
}

int Find(int u) 
{
	for(int i = NN - 1; i >= 0; i --) 
	{
		int pu = p[i][u];
		if(pu == -1 || get(In[pu],Out[pu])) continue;
		u = pu;
	}
	u = p[0][u];
	return u;
}

void add_Ve(int v) 
{
	if(!Ve.empty()) 
	{
		int Root = get_Root();
		int new_Root = lca(Root, v);
		if(new_Root != Root) 
			res += dist(Root, v);
		else if(get(In[v], Out[v]) == 0) 
			res += dist(Find(v), v);
	}
	add(In[v], 1);
	Ve.insert(v);
}

void del_Ve(int v) 
{
	add(In[v], -1);
	Ve.erase(v);
	if(!Ve.empty()) 
	{
		int Root = get_Root();
		int new_Root = lca(Root, v);
		if(Root != new_Root) 
			res -= dist(v, Root);
		else if(get(In[v], Out[v]) == 0) 
			res -= dist(Find(v), v);
	}

}

int main() 
{
	scanf("%d", &n);
	g.resize(n + 1);
	for(int u, v, w, i = 0;i < n - 1; i ++) 
	{
		scanf("%d %d %d", &u, &v, &w);
		g[u].pb(mp(v, w));
		g[v].pb(mp(u, w));
	}
	for(int i = 0; i < NN; i ++) 
		p[i].resize(n + 1, -1);
	h.resize(n + 1);
	sum.resize(n + 1);
	In.resize(n + 1);
	Out.resize(n + 1);
	dfs(1);
	for(int i = 1; i < NN; i ++) 
		for(int j = 1; j <= n; j ++) 
		{
			int x = p[i - 1][j];
			if(x != -1) p[i][j] = p[i - 1][x];
		}
	fen.resize(n + n);
	int m;
	scanf("%d", &m);
	char op;
	while(m --)
	{
		scanf(" %c", &op);
		if(op == '?') 
		{
			printf("%I64d\n", res);
			continue;
		}
		int x;
		scanf("%d", &x);
		if(op == '+') add_Ve(x);
		else del_Ve(x);

	}
	return 0;
}