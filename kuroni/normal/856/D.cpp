#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

struct TEdge
{
	int u, v, c;
}	tmp;

vector <int> adj[200005], par[200005];
vector <TEdge> save[200005];
int n, m, i, t, lpos[200005], rpos[200005], h[200005], cur = 0;
long long f[200005], bit[400005];

void upd(int u, int v)
{
	while (u <= 2 * n)
	{
		bit[u] += v;
		u += u & -u;
	}
}

long long que(int u)
{
	long long ans = 0;
	while (u > 0)
	{
		ans += bit[u];
		u -= u & -u;
	}
	return ans;
}

void DFS_1(int u, int p)
{
	lpos[u] = ++cur;
    if (u != 1)
    {
        h[u] = h[p] + 1;
        par[u].push_back(p);
        for (int i = 1; (1 << i) <= h[u]; i++)
            par[u].push_back(par[par[u][i - 1]][i - 1]);
    }
	for (int v: adj[u])
		DFS_1(v, u);
	rpos[u] = ++cur;
}

int LCA(int x, int y)
{
    int i, j;
    if (h[x] < h[y])
        swap(x, y);
    for (i = 0; (1 << i) <= h[x] - h[y]; i++)
    {
        if (((h[x] - h[y]) >> i) & 1)
            x = par[x][i];
    }
    if (x == y)
        return x;
    for (i = 0; (1 << i) <= h[x]; i++)
        j = i;
    for (i = j; i >= 0; i--)
        if ((1 << i) <= h[x])
            if (par[x][i] != par[y][i])
            {
                x = par[x][i];
                y = par[y][i];
            }
    return par[x][0];
}

void DFS_2(int u)
{
	long long sum = 0, diff = 0, exc;
	for (int v: adj[u])
	{
		DFS_2(v);
		sum += f[v];
	}
	exc = que(lpos[u] - 1);
	while (!save[u].empty())
	{
		tmp = save[u].back(); save[u].pop_back();
		diff = max(diff, 2 * exc - que(lpos[tmp.u]) - que(lpos[tmp.v]) + tmp.c);
	}
	f[u] = sum + diff; upd(lpos[u], diff); upd(rpos[u], -diff);
}

int main()
{
	memset(f, 0, sizeof(f)); memset(bit, 0, sizeof(bit));
	scanf("%d%d", &n, &m);
	for (i = 2; i <= n; i++)
	{
		scanf("%d", &t);
		adj[t].push_back(i);
	}
	DFS_1(1, 0);
	while (m--)
	{
		scanf("%d%d%d", &tmp.u, &tmp.v, &tmp.c);
		save[LCA(tmp.u, tmp.v)].push_back(tmp);
	}
	DFS_2(1);
	printf("%I64d", f[1]);
}