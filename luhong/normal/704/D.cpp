#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm> 
#define MM 1010000
#define MN 201000

typedef long long ll;

int h[MN], nxt[MM], to[MM], id[MM], K = 1; ll cap[MM];
int iter[MN], lvl[MN], q[MN], hh = 0, tt = 0;
int n, m, r, b;
int x[MN], y[MN], bx[MN], by[MN];
int cntx[MN], cnty[MN];
ll d[MN], ans, sum = 0;
int Minx[MN], Miny[MN];
char s[MN];

void ins(int u, int v, ll c) {nxt[++K] = h[u]; h[u] = K; to[K] = v; cap[K] = c;}
void insw(int u, int v, ll c) {ins(u, v, c); ins(v, u, 0);}

bool bfs(int S, int T)
{
	memset(lvl, 0, sizeof(lvl));
	lvl[S] = 1;
	hh = 0; tt = 0; q[tt++] = S;
	while(hh < tt)
	{
		int u = q[hh++]; iter[u] = h[u];
		for(int i = h[u]; i; i = nxt[i])
		{
			if(cap[i ^ 1] && !lvl[to[i]])
			{
				lvl[to[i]] = lvl[u] + 1;
				q[tt++] = to[i];
			}
		}
	}
	if(!lvl[T]) return 0;
	return 1;
}
 
ll dfs(int u, int T, ll f)
{
	if(u == T) return f;
	ll used = 0;
	for(int &i = iter[u]; i; i = nxt[i])
	{
		if(cap[i] && lvl[to[i]] == lvl[u] - 1)
		{
			ll w = dfs(to[i], T, std::min(cap[i], f - used));
			if(w)
			{
				cap[i] -= w; cap[i ^ 1] += w; used += w; 
				if(used == f) return f;
			}
		}
	}
	return used;
}

ll dinic(int S, int T)
{
	ll flow = 0;
	while(bfs(T, S))
	{
		ll f;
		do {
			f = dfs(S, T, 1e18);
			flow += f;
		} while(f);
	}
	return flow;
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &r, &b);
	bool ok = 0;
	if(r < b) std::swap(r, b), ok = 1;
	for(int i = 1; i <= n; i++) 
	{
		scanf("%d%d", &x[i], &y[i]);
		bx[i] = x[i]; by[i] = y[i];
	}
	std::sort(bx + 1, bx + n + 1); int N = std::unique(bx + 1, bx + n + 1) - bx - 1;
	std::sort(by + 1, by + n + 1); int M = std::unique(by + 1, by + n + 1) - by - 1;
	for(int i = 1; i <= n; i++)
	{
		x[i] = std::lower_bound(bx + 1, bx + N + 1, x[i]) - bx;
		y[i] = std::lower_bound(by + 1, by + M + 1, y[i]) - by;
		cntx[x[i]]++; cnty[y[i]]++;
	}
	
	memset(Minx, 0x3f, sizeof(Minx));
	memset(Miny, 0x3f, sizeof(Miny));
	for(int i = 1; i <= m; i++)
	{
		int t, w, d; scanf("%d%d%d", &t, &w, &d);
		if(t == 1)
		{
			int p = std::lower_bound(bx + 1, bx + N + 1, w) - bx;
			if(bx[p] == w) w = p;
			else w = 0;
		}
		else
		{
			int p = std::lower_bound(by + 1, by + M + 1, w) - by;
			if(by[p] == w) w = p;
			else w = 0;
		}
		if(t == 1) Minx[w] = std::min(Minx[w], d);
		if(t == 2) Miny[w] = std::min(Miny[w], d);
	}
	
	int S = N + M + 1, T = S + 1;
	for(int i = 1; i <= N; i++)
	{
		int l = ((cntx[i] - Minx[i]) & 1) ? (cntx[i] - Minx[i] + 1) / 2 : (cntx[i] - Minx[i]) / 2;
		int r = (cntx[i] + Minx[i]) / 2;
		l = std::max(l, 0);
		if(l > r) return 0 * puts("-1");
		insw(S, i, r - l);
		d[S] += l; d[i] -= l;
	}
	for(int i = 1; i <= M; i++)
	{
		int l = ((cnty[i] - Miny[i]) & 1) ? (cnty[i] - Miny[i] + 1) / 2 : (cnty[i] - Miny[i]) / 2;
		int r = (cnty[i] + Miny[i]) / 2;
		l = std::max(l, 0);
		if(l > r) return 0 * puts("-1");
		insw(i + N, T, r - l);
		d[i + N] += l; d[T] -= l;
	}
	
	for(int i = 1; i <= n; i++)	id[K + 1] = i, insw(x[i], y[i] + N, 1);
	int SS = T + 1, TT = SS + 1;
	for(int i = 1; i <= T; i++)
	{
		if(d[i] > 0) insw(i, TT, d[i]), sum += d[i];
		if(d[i] < 0) insw(SS, i, -d[i]);
	}
	insw(T, S, 1e18);
	if(sum != dinic(SS, TT)) return 0 * puts("-1");
	
	for(int i = h[SS]; i; i = nxt[i]) cap[i] = cap[i ^ 1] = 0;
	for(int i = h[TT]; i; i = nxt[i]) cap[i] = cap[i ^ 1] = 0;
	ans = cap[K]; cap[K] = cap[K ^ 1] = 0;
	
	printf("%lld\n", 1ll * b * n + (r - b) * (ans - dinic(T, S)));
	for(int i = 1; i <= N; i++)
		for(int j = h[i]; j; j = nxt[j])
			if(N + 1 <= to[j] && to[j] <= N + M)
			{
				if(cap[j] ^ ok) s[id[j]] = 'b';
				else s[id[j]] = 'r';
			}
	printf("%s\n", s + 1);
}