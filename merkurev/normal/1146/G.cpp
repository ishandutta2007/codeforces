#ifndef LOCAL
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#endif

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


const int inf = 0x3f3f3f3f;

struct edge
{
	int ver, cap, flow, op;
	edge(){}
	edge(int v, int c, int o)
	{
		ver = v;
		cap = c;
		flow = 0;
		op = o;
	}
};

const int N = 10500;

int d[N], q[N];
vector <edge> v[N];
int ptr[N];
int n;
int s, t;

void add_edge(int from, int to, int cap)
{
//    eprintf("%d -> %d : %d\n", from, to, cap);
	v[from].push_back(edge(to, cap, v[to].size()));
	v[to].push_back(edge(from, 0, v[from].size() - 1));
}

int T;

bool bfs()
{
	memset(d, 0x3f, sizeof(d));
	int left = 0, right = 1;
	q[0] = s;
	d[s] = 0;
	while (left < right)
	{
		int ver = q[left++];
		for (int i = 0; i < (int)v[ver].size(); ++i)
			if (v[ver][i].cap - v[ver][i].flow >= T && d[v[ver][i].ver] == inf)
			{
				d[v[ver][i].ver] = d[ver] + 1;
				q[right++] = v[ver][i].ver;
			}
	}
	return d[t] != inf;
}

int xmin(int x, int y)
{
	return x < y ? x : y;
}

int dfs(int u, int flow)
{
	if (flow == 0 || u == t)
		return flow;
	int f = 0;
	int i = 0;
	for (i = ptr[u]; i < (int)v[u].size(); ++i)
		if (d[v[u][i].ver] == d[u] + 1 && v[u][i].cap - v[u][i].flow >= T)
		{
			int cflow = dfs(v[u][i].ver, xmin(flow - f, v[u][i].cap - v[u][i].flow));
			if (cflow > 0)
			{
				f += cflow;
				v[u][i].flow += cflow;
				v[v[u][i].ver][v[u][i].op].flow -= cflow;
			}
			if (flow - f == 0)
				break;
		}
	ptr[u] = i;
	return f;
}

int find_flow()
{
    int ans = 0;
	int i;
	for (T = (1 << 30); T > 0; T /= 2)
	{
		while (1)
		{
			if (!bfs())
				break;
			for (i = 0; i < n; ++i)
				ptr[i] = 0;
			ans += dfs(s, inf);
		}
	}
    return ans;
}

const int X = 55;
int nn, h, m;
bool bused[X][X];

int getRestrV(int id)
{
    return id;
}

int getBuildV(int i, int j)
{
    return X + i * X + j;
}

int getSourceV()
{
    return X + X * X;
}

int getSinkV()
{
    return X * X + X + 1;
}

const int MX = (int) 1e7;

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    scanf("%d%d%d", &nn, &h, &m);

    for (int i = 0; i < m; i++)
    {
        int l, r, x, c;
        scanf("%d%d%d%d", &l, &r, &x, &c);
        l--;
        r--;
        add_edge(getRestrV(i), getSinkV(), c);
        for (int j = l; j <= r; j++)
            for (int k = x + 1; k <= h; k++)
            {
                bused[j][k] = true;
                add_edge(getBuildV(j, k), getRestrV(i), MX);
            }
    }
    for (int i = 0; i < nn; i++)
        for (int j = 1; j <= h; j++)
            if (bused[i][j])
                add_edge(getSourceV(), getBuildV(i, j), j * j - (j - 1) * (j - 1));

    
    s = getSourceV();
    t = getSinkV();
    n = t + 1;
    int ans = nn * h * h;
    int flow = find_flow();
    ans -= flow;
    printf("%d\n", ans);


	return 0;
}