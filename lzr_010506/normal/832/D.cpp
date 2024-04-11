#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define eps 1e-9
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int n, q;
int p[100010];
vector<int> e[100010];
int dep[100010], fa[100010][20];

void dfs(int u, int d = 0)
{
    dep[u] = d;
    fa[u][0] = p[u];
    rep(i, 1, 19)
        fa[u][i] = (fa[u][i - 1] == -1) ? -1 : fa[fa[u][i - 1]][i - 1];
    for (int v : e[u]) 
    	if (v != p[u]) 
    		dfs(v, d + 1);
}

int lca(int u, int v)
{
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 20 - 1; i >= 0; i --)
        if (dep[u] - (1 << i) >= dep[v]) u = fa[u][i];
    if (u == v) return v;
    for (int i = 20 - 1; i >= 0; i --)
        if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

int Dis(int u, int v)
{
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int main()
{
	n = read();
	q = read();
    p[0] = -1;
    rep(i, 1, n - 1)
    {
        p[i] = read();
        p[i] --;
        e[p[i]].pb(i);
    }
    dfs(0);
    while(q --)
    {
    	int a, b, c;
		a = read();
		b = read();
		c = read();
		a --, b --, c --;
        int ab = Dis(a, b), bc = Dis(b, c), ca = Dis(c, a);
        int s = (ab + bc + ca) / 2;
        int x = s - ab, y = s - bc, z = s - ca;
        printf("%d\n", max(max(x, y), z) + 1);
    }

    return 0;
}