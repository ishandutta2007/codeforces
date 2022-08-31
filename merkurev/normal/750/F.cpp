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


const int N = (1 << 8);
vector <int> g[N];
bool used[N];
int d[N];

void init()
{
	memset(d, -1, sizeof d);
	memset(used, false, sizeof used);
	for (int i = 0; i < N; i++)
		g[i].clear();
}

void ask(int v)
{
	if (used[v] ) return;
	printf("? %d\n", v);
	fflush(stdout);
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		int x;
		scanf("%d", &x);
		if (find(g[v].begin(), g[v].end(), x) != g[v].end() ) continue;
		g[v].push_back(x);
		g[x].push_back(v);
	}
	used[v] = true;
}

void answer(int v)
{
	printf("! %d\n", v);
	fflush(stdout);
}

int qu[N];

void solve()
{
	init();

	int h;
	scanf("%d", &h);

	int s = 1;
	ask(s);

	if ((int) g[s].size() == 2)
	{
		answer(s);
		return;
	}

	int layer = -1;
	int v, ch;

	if (g[s].size() == 1)
	{
		layer = h - 2;
		ch = s;
		v = g[s][0];
	}
	else
	{
		int l = 0, r = 0;
		qu[r++] = g[s][0];
		qu[r++] = g[s][1];
		d[qu[0] ] = 1;
		d[qu[1] ] = 1;
		d[s] = 0;

		int leaf = -1;
		while (l < r && (leaf == -1 || d[qu[l] ] == d[leaf] ) )
		{
			int vv = qu[l++];
			int sz = (int) g[vv].size();
			ask(vv);
			int nsz = (int) g[vv].size();
			if (nsz == sz)
			{
				if (sz != 1) throw;
				if (leaf != -1)
				{
					leaf = -1;
					break;
				}
				leaf = vv;
			}
			if (nsz == 2)
			{
				answer(vv);
				return;
			}
			int nx = g[vv].back();
			d[nx] = d[vv] + 1;
			qu[r++] = nx;
		}
		ch = s;
		if (leaf == -1)
		{
			v = g[s][2];
		}
		else
		{
			if ((int)g[qu[l - 2] ].size() == 1)
				v = g[s][1];
			else
				v = g[s][0];
		}
		eprintf(">>> qu[l - 2] = %d\n", qu[l - 2]);
		layer = h - d[qu[l - 2] ] - 2;
	}
	while (true)
	{
		eprintf(">>> v = %d, ch = %d, layer = %d\n", v, ch, layer);
		if (layer == 0) 
		{
			answer(v);
			return;
		}
		if (layer == 1)
		{
			ask(v);
			eprintf("<<< %d %d %d\n", g[v][0], g[v][1], g[v][2] );
			int a = g[v][0];
			int b = g[v][1];
			if (a == ch) a = g[v][2];
			if (b == ch) b = g[v][2];
			ask(a);
			if ((int) g[a].size() == 2)
			{
				answer(a);
				return;
			}
			answer(b);
			return;
		}
		if (layer == 2)
		{
			ask(v);
			int a = g[v][0];
			int b = g[v][1];
			if (a == ch) a = g[v][2];
			if (b == ch) b = g[v][2];
			ask(a);
			ask(b);
			int a1, a2;
			if ((int) g[a].size() == 3)
			{
				a1 = g[a][0];
				a2 = g[a][1];
				if (a1 == v)
					a1 = g[a][2];
				if (a2 == v)
					a2 = g[a][2];
			}
			else
			{
				a1 = a2 = a;
			}
			int b1, b2;
			if ((int) g[b].size() == 3)
			{
				b1 = g[b][0];
				b2 = g[b][1];
				if (b1 == v)
					b1 = g[b][2];
				if (b2 == v)
					b2 = g[b][2];
			}
			else
			{
				b1 = b2 = b;
			}
			ask(a1);
			if ((int) g[a1].size() == 2)
			{
				answer(a1);
				return;
			}
			ask(a2);
			if ((int) g[a2].size() == 2)
			{
				answer(a2);
				return;
			}
			ask(b1);
			if ((int) g[b1].size() == 2)
			{
				answer(b1);
				return;
			}
			answer(b2);
			return;
		}


		ask(v);
		int x = g[v][0];
		if (x == ch)
			x = g[v][1];
		int px = v;
		int sx = x;
		for (int clayer = layer + 1; clayer < h - 1; clayer++)
		{
			ask(x);
			if ((int) g[x].size() == 2)
			{
				answer(x);
				return;
			}
			int nx = g[x][0];
			if (nx == px)
				nx = g[x][1];
			px = x;
			x = nx;
		}
		ask(x);
		if ((int) g[x].size() == 2)
		{
			answer(x);
			return;
		}
		if ((int) g[x].size() == 3)
		{
			ch = v;
			v = sx;
		}
		else
		{
			int nv = g[v][1];
			if (nv == ch || nv == sx)
				nv = g[v][2];
			ch = v;
			v = nv;
		}
		layer--;
	}
	
}


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
		solve();



	return 0;
}