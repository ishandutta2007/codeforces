#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int N = (int) 2e5 + 100;
int e[N][3];
vector <int> g[N], tree[N];
int ans[N];

int getOth(int eid, int v)
{
	return (v ^ e[eid][0] ^ e[eid][1] );
}

const int LOG = 20;

int h[N];
int par[N][LOG], mxup[N][LOG];

void dfsTree(int v, int cpar, int ccost, int ch)
{
	h[v] = ch;
	par[v][0] = cpar;
	mxup[v][0] = ccost;
	for (int i = 1; i < LOG; i++)
	{
		par[v][i] = par[par[v][i - 1] ][i - 1];
		mxup[v][i] = max(mxup[v][i - 1], mxup[par[v][i - 1] ][i - 1] );
	}

	for (int eid : tree[v] )
	{
		int to = getOth(eid, v);
		if (to == cpar) continue;
		dfsTree(to, v, e[eid][2], ch + 1);
	}
}


set <pair <int, int> > costs[N];

int getAnsBySet(int id)
{
	if (costs[id].empty() ) return -1;
	return (costs[id].begin()->first) - 1;
}

void change(int id, pair <int, int> p)
{
	if (costs[id].count(p) )
		costs[id].erase(p);
	else
		costs[id].insert(p);
}

int merge(int a, int b)
{
	if ((int) costs[a].size() < (int) costs[b].size() )
		swap(a, b);
	for (auto p : costs[b] )
		change(a, p);
	return a;
}

int dfsSolve(int v, int cpar)
{
	int id = v;
	
	for (int eid : tree[v] )
	{
		int to = getOth(eid, v);
		if (to == cpar) continue;
		int nid = dfsSolve(to, v);
		ans[eid] = getAnsBySet(nid);
		id = merge(id, nid);
	}

	for (int eid : g[v] )
		change(id, make_pair(e[eid][2], eid) );

	return id;
}


int goUp(int v, int d)
{
	for (int i = 0; i < LOG; i++)
		if (d & (1 << i) )
			v = par[v][i];
	return v;
}

int getMxUp(int v, int d)
{
	int answ = 0;
	for (int i = 0; i < LOG; i++)
		if (d & (1 << i) )
		{
			answ = max(answ, mxup[v][i] );
			v = par[v][i];
		}
	return answ;
}

int LCA(int a, int b)
{
	if (h[a] < h[b] ) swap(a, b);
	a = goUp(a, h[a] - h[b] );
	if (a == b) return a;
	for (int i = LOG - 1; i >= 0; i--)
		if (par[a][i] != par[b][i] )
		{
			a = par[a][i];
			b = par[b][i];
		}
	return par[a][0];
}

int getMxP(int a, int l)
{
	return getMxUp(a, h[a] - h[l] );
}

int getMx(int a, int b)
{
	int l = LCA(a, b);
	int ansa = getMxP(a, l);
	int ansb = getMxP(b, l);
	return max(ansa, ansb);
}

vector <int> eids;
void addEdge(int id)
{
	g[e[id][0] ].push_back(id);
	g[e[id][1] ].push_back(id);
	eids.push_back(id);
}

void addTreeEdge(int id)
{
	tree[e[id][0] ].push_back(id);
	tree[e[id][1] ].push_back(id);
}

int pr[N];
int sz[N];

int getP(int x)
{
	if (x == pr[x] ) return x;
	return pr[x] = getP(pr[x] );
}

bool uni(int a, int b)
{
	a = getP(a);
	b = getP(b);
	if (a == b) return false;

	if (sz[a] < sz[b] ) swap(a, b);
	pr[b] = a;
	sz[a] += sz[b];

	return true;
}


int p[N];
bool cmpE(int a, int b)
{
	return e[a][2] < e[b][2];
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &e[i][0], &e[i][1], &e[i][2] );
		e[i][0]--;
		e[i][1]--;
		p[i] = i;
		ans[i] = -2;
	}
	sort(p, p + m, cmpE);
	
	for (int i = 0; i < n; i++)
	{
		pr[i] = i;
		sz[i] = 1;
	}
	for (int _i = 0; _i < m; _i++)
	{
		int i = p[_i];
		if (uni(e[i][0], e[i][1] ) )
		{
//			eprintf("%d %d : %d\n", e[i][0], e[i][1], e[i][2] );
			addTreeEdge(i);
		}
		else
		{
//			eprintf("- %d %d : %d\n", e[i][0], e[i][1], e[i][2] );
			addEdge(i);
		}
	}
//	eprintf("\n");

	dfsTree(0, 0, 0, 0);

	for (int eid : eids)
		ans[eid] = getMx(e[eid][0], e[eid][1] ) - 1;

	dfsSolve(0, 0);

	for (int i = 0; i < m; i++)
		printf("%d ", ans[i] );
	printf("\n");

	return 0;
}