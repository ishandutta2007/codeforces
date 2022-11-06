#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm> 

using namespace std;

int n, m;
long long dep[101000];
int a[201000], b[201000], st[201000][20], dep2[101000], tot = 0, fi[101000];
int u[101000], v[101000], c[101000];
int f[101000];
long long d[101000][42];
int o[44], cnt = 0, O[44], cnt2 = 0, id[101000];
typedef pair<long long, int> P;
priority_queue<P, vector<P>, greater<P> > pq;
int h[101000], nxt[201000], to[201000], cost[201000], K = 0;

void ins(int u, int v, int c) {nxt[++K] = h[u]; h[u] = K; to[K] = v; cost[K] = c;}

int Find(int x) {return x == f[x] ? x : f[x] = Find(f[x]);}

bool hb(int u, int v)
{
	u = Find(u), v = Find(v);
	if(u == v) return 0;
	f[u] = v; return 1;
}

void dij(int S)
{
	d[o[S]][S] = 0;
	pq.push(P(d[o[S]][S], o[S]));
	while(!pq.empty())
	{
		P p = pq.top(); pq.pop();
		int u = p.second;
		if(d[u][S] < p.first) continue;
		for(int i = h[u]; i; i = nxt[i])
		{
			if(d[to[i]][S] > d[u][S] + cost[i])
			{
				d[to[i]][S] = d[u][S] + cost[i];
				pq.push(P(d[to[i]][S], to[i]));
			}
		}
	}
}

void dfs(int x, int fa)
{
	dep2[x] = dep2[fa] + 1; a[++tot] = x;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == fa) continue;
		dep[to[i]] = dep[x] + cost[i];
		dfs(to[i], x);
		a[++tot] = x;
	}
}

void init()
{
	for(int i = 1; i <= tot; i++) st[i][0] = a[i];
	for(int i = 1; i <= 18; i++)
		for(int j = 1; j + (1 << i) - 1 <= tot; j++)
		{
			if(dep2[st[j][i - 1]] < dep2[st[j + (1 << (i - 1))][i - 1]]) st[j][i] = st[j][i - 1];
			else st[j][i] = st[j + (1 << (i - 1))][i - 1];
		}
	for(int i = 1; i <= tot; i++)
		if(!fi[a[i]]) fi[a[i]] = i;
	for(int i = 2; i <= tot; i <<= 1) b[i] = b[i / 2] + 1;
	for(int i = 1; i <= tot; i++) if(!b[i]) b[i] = b[i - 1];
}

int lca(int u, int v)
{
	int l = fi[u], r = fi[v];
	if(l > r) std::swap(l, r);
	int len = r - l + 1;
//	printf("%d %d %d %d\n", l, r, len, 1<<b[len]);
	if(dep2[st[l][b[len]]] < dep2[st[r - (1 << b[len]) + 1][b[len]]]) return st[l][b[len]];
	return st[r - (1 << b[len]) + 1][b[len]];
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u[i], &v[i], &c[i]);
		ins(u[i], v[i], c[i]); ins(v[i], u[i], c[i]);
	}
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= m; i++)
	{
		if(!hb(u[i], v[i])) o[++cnt] = u[i], o[++cnt] = v[i], O[++cnt2] = i;
	}
	sort(o + 1, o + cnt + 1); cnt = unique(o + 1, o + cnt + 1) - o - 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= cnt; j++) d[i][j] = (1ll << 60);
	for(int i = 1; i <= cnt; i++) id[o[i]] = i, dij(i);
	memset(h, 0, sizeof(h)); K = 0;
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= m; i++)
	{
		if(hb(u[i], v[i])) ins(u[i], v[i], c[i]), ins(v[i], u[i], c[i]);
	}
	dfs(1, 0);
//	for(int i = 1; i <= tot; i++) printf("%d ", a[i]);
	init();
	int q; scanf("%d", &q);
	for(int i = 1; i <= q; i++)
	{
		int U, V; scanf("%d%d", &U, &V);
		int L = lca(U, V); //printf("%d\n", L);
		long long ans = dep[U] + dep[V] - 2 * dep[L];
		for(int j = 1; j <= cnt2; j++)
		{
		//	printf("%d %d %d\n", id[u[O[j]]], id[v[O[j]]], c[O[j]]);
			ans = min(ans, c[O[j]] + min(d[U][id[u[O[j]]]] + d[V][id[v[O[j]]]], d[V][id[u[O[j]]]] + d[U][id[v[O[j]]]]));
		}
	//	printf("%d\n", id[4]);
		printf("%lld\n", ans);
	}
	return 0;
}