#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


#ifdef LOCAL
	#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

const int INF = (int) 1e9 + 100;
const int maxn = (int) 5e5 + 100;
int h[maxn], s[maxn];
vector <int> g[maxn];
vector <int> h2here[maxn];
int hv[maxn];


void dfs(int v, int par, int mv, int h1, int h2)
{
	if (h[v] < h1)
	{
		mv = v;
		h2 = h1;
		h1 = h[v];
	}
	else if (h[v] < h2)
	{
		h2 = h[v];
	}
	hv[v] = h1;
	h2here[mv].push_back(h2);

	for (int i = 0; i < (int) g[v].size(); i++)
	{
		int nv = g[v][i];
		if (nv == par)
			continue;
		dfs(nv, v, mv, h1, h2);
	}
}

const int ST = 19;
const int LEVEL = (1 << ST);
const int SZ = (LEVEL << 1);


int tree[SZ];
int add[SZ];

void initVal(int pos, int val)
{
	tree[LEVEL + pos] = val;
}
void initTree()
{
	for (int i = LEVEL - 1; i >= 1; i--)
	{
		tree[i] = min(tree[2 * i], tree[2 * i + 1] );
	}
}
void push(int v)
{
	add[2 * v] += add[v];
	tree[2 * v] += add[v];
	add[2 * v + 1] += add[v];
	tree[2 * v + 1] += add[v];
	add[v] = 0;
}
void addVal(int v, int l, int r, int tl, int tr, int val)
{
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r)
	{
		add[v] += val;
		tree[v] += val;
		return;
	}
	push(v);
	int tm = (tl + tr) / 2;
	addVal(2 * v, l, r, tl, tm, val);
	addVal(2 * v + 1, l, r, tm, tr, val);

	tree[v] = min(tree[2 * v], tree[2 * v + 1] );
}

void addSemi(int l, int r, int val)
{
	addVal(1, l, r, 0, LEVEL, val);
}

int getFirstNeg(int v)
{
	if (v >= LEVEL)
		return v - LEVEL;
	push(v);
	if (tree[2 * v] < 0)
		return getFirstNeg(2 * v);
	return getFirstNeg(2 * v + 1);
}

int n;
bool cmp(const int &a, const int &b)
{
	return a > b;
}

int firstLEQ(int val)
{
	return lower_bound(s, s + n, val, cmp) - s;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &h[i] );
	}
	for (int i = 0; i < n - 1; i ++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0, -1, -1, INF, INF);
	
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
		scanf("%d", &s[i] );
	sort(s, s + n);
	reverse(s, s + n);

	for (int i = 0; i <= n; i++)
	{
		initVal(i, -(i + 1) );
	}
	initTree();
	

	for (int i = 0; i < n; i++)
	{
		int pos = firstLEQ(hv[i] );
		addSemi(pos, n, 1);
	}
	
	int ans = INF;
	if (getFirstNeg(1) == n)
	{
		printf("0\n");
		return 0;
	}
	int x = getFirstNeg(1);
	int xh = s[x];

	for (int v = 0; v < n; v++)
	{
		int curans = xh - hv[v];
		if (curans <= 0)
			continue;

		int pos = firstLEQ(h[v] );
		addSemi(pos, n, - (int) h2here[v].size() );

//		eprintf("v = %d, h[v] = %d, curans = %d, pos = %d\n", v, h[v], curans, pos);

		for (int i = 0; i < (int) h2here[v].size(); i++)
		{
			int nh = min(xh, h2here[v][i] );
			int _pos = firstLEQ(nh);
			addSemi(_pos, n, 1);
		}

		int fn = getFirstNeg(1);
//		eprintf("fn = %d\n", fn);
		if (fn == n)
			ans = min(ans, curans);

		addSemi(pos, n, (int) h2here[v].size() );
		
		for (int i = 0; i < (int) h2here[v].size(); i++)
		{
			int nh = min(xh, h2here[v][i] );
			int _pos = firstLEQ(nh);
			addSemi(_pos, n, -1);
		}
	}

	if (ans == INF)
		ans = -1;
	printf("%d\n", ans);

	return 0;
}