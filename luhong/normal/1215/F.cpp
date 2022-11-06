#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MN 801000

int h[MN], nxt[5 * MN], to[5 * MN], K = 0;
int dfn[MN], low[MN], D = 0;
int st[MN], inq[MN], top = 0;
int id[MN], tot = 0;
std::vector<int> b[MN];
int x[MN], y[MN], u[MN], v[MN], l[MN], r[MN];
int n, p, M, m; 
int L[MN], R[MN];
struct xxx{
	int l, r;
}q[MN * 2];
int Q = 0;

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

bool cmp(xxx a, xxx b) {return a.l < b.l;}

void tarjan(int x)
{
	dfn[x] = low[x] = ++D;
	st[++top] = x; inq[x] = 1;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(!dfn[to[i]])
		{
			tarjan(to[i]);
			low[x] = std::min(low[x], low[to[i]]);
		}
		else if(inq[to[i]]) low[x] = std::min(low[x], dfn[to[i]]);
	}
	if(dfn[x] == low[x])
	{
		++tot;
		do
		{
			id[st[top]] = tot; 
			b[tot].push_back(st[top]);
			inq[st[top]] = 0;
		} while(st[top--] != x);
	}
}

void build()
{
	memset(h, 0, sizeof(h)); K = 0;
	for(int i = 1; i <= n; i++)
	{
		ins(2 * x[i] - 1, 2 * y[i]);
		ins(2 * y[i] - 1, 2 * x[i]);
	}
	for(int i = 1; i <= m; i++)
	{
		ins(2 * u[i], 2 * v[i] - 1);
		ins(2 * v[i], 2 * u[i] - 1);
	}
}

int main()
{
	scanf("%d%d%d%d", &n, &p, &M, &m);
	for(int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
	for(int i = 1; i <= p; i++) scanf("%d%d", &l[i], &r[i]);
	for(int i = 1; i <= m; i++) scanf("%d%d", &u[i], &v[i]);
	
	build();
	for(int i = 1; i <= 2 * p; i++) L[i] = 0, R[i] = M + 1;
	for(int i = 1; i <= 2 * p; i++) if(!dfn[i]) tarjan(i);
	for(int i = 1; i <= p; i++) if(id[2 * i - 1] == id[2 * i]) return 0 * puts("-1");
	
	memset(h, 0, sizeof(h)); K = 0;
	for(int i = 1; i <= n; i++)
	{
		ins(id[2 * x[i] - 1], id[2 * y[i]]);
		ins(id[2 * y[i] - 1], id[2 * x[i]]);
	}
	for(int i = 1; i <= m; i++)
	{
		ins(id[2 * u[i]], id[2 * v[i] - 1]);
		ins(id[2 * v[i]], id[2 * u[i] - 1]);
	}
	
	for(int x = 1; x <= tot; x++)
	{
		for(int i = h[x]; i; i = nxt[i])
		{
			L[x] = std::max(L[x], L[to[i]]);
			R[x] = std::min(R[x], R[to[i]]);
		}
		
		for(int i = 0; i < b[x].size(); i++)
			if(!(b[x][i] & 1))
				L[x] = std::max(L[x], l[b[x][i] >> 1] - 1),
				R[x] = std::min(R[x], r[b[x][i] >> 1] + 1);
		
		if(L[x] >= R[x]) L[x] = R[x] - 1;
		
		for(int i = 0; i < b[x].size(); i++)
			if(b[x][i] & 1)
			{
				int _l = l[b[x][i] + 1 >> 1], _r = r[b[x][i] + 1 >> 1];
				q[++Q].l = 1, q[Q].r = std::min(_l - 1, L[x]);
				if(_r < L[x]) q[++Q].l = _r + 1, q[Q].r = L[x];
				if(_l > R[x]) q[++Q].l = R[x], q[Q].r = _l - 1;
				q[++Q].l = std::max(_r + 1, R[x]), q[Q].r = M;
			}
	}
	
	std::sort(q + 1, q + Q + 1, cmp);
	int Max = 0, f = -1;
	for(int i = 1; i <= Q; i++)
	{
		if(q[i].l > Max + 1) {f = Max + 1; break;}
		else Max = std::max(Max, q[i].r);
	}
	if(f == -1 && Max < M) f = M;
	if(f == -1) return 0 * puts("-1");
	
	build();
	for(int i = 1; i <= p; i++) if(f < l[i] || f > r[i]) ins(2 * i, 2 * i - 1);
	memset(dfn, 0, sizeof(dfn)); top = 0; tot = 0; D = 0; 
	for(int i = 1; i <= 2 * p; i++) if(!dfn[i]) tarjan(i);
	int tt = 0;
	for(int i = 1; i <= p; i++)
		if(id[2 * i - 1] > id[2 * i]) ++tt;
	printf("%d %d\n", tt, f);
	for(int i = 1; i <= p; i++)
		if(id[2 * i - 1] > id[2 * i]) printf("%d ", i);
	return 0;
}