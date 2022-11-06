#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define MN 201000

int h[MN], nxt[2 * MN], to[2 * MN], K = 1;
int U[MN], V[MN], id[MN], tot = 0;
int dfn[MN], low[MN], D = 0;
int st[MN], top = 0;
int r[MN], len = 0, d[MN];
bool inq[MN], inr[MN], vis[MN], flag = 0;
int ans[MN], tt = 0;
int fr, to1, to2;
std::vector<int> v[MN];
std::vector<int> e[MN];
int used[MN];

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void tarjan(int x, int fa)
{
	dfn[x] = low[x] = ++D;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == fa) continue;
		if(!dfn[to[i]])
		{
			st[++top] = i / 2;
			tarjan(to[i], x);
			low[x] = std::min(low[x], low[to[i]]);
			if(low[to[i]] >= dfn[x])
			{
				++tot; 
				do {
					if(used[U[st[top]]] != tot) v[tot].push_back(U[st[top]]), used[U[st[top]]] = tot;
					if(used[V[st[top]]] != tot) v[tot].push_back(V[st[top]]), used[V[st[top]]] = tot;
					e[tot].push_back(st[top]);
				} while(st[top--] != i / 2);
			}
		}
		else if(dfn[to[i]] < dfn[x]) st[++top] = i / 2, low[x] = std::min(low[x], dfn[to[i]]);
	}
}

void get_ring(int x, int fa)
{
	if(len) return;
	if(inq[x])
	{
		do {
			r[++len] = st[top];
			inr[st[top]] = 1;
		} while(st[top--] != x);
		return;
	}
	st[++top] = x; inq[x] = 1;
	for(int i = h[x]; i; i = nxt[i]) if(to[i] != fa) get_ring(to[i], x);
}

void get_path(int x)
{
	if(vis[x]) return; 
	ans[++tt] = x; vis[x] = 1;
	if(x != fr && inr[x]) {flag = 1; return;}
	for(int i = h[x]; i; i = nxt[i])
	{
		if(x == fr && (to[i] == to1 || to[i] == to2)) continue;
		get_path(to[i]);
		if(flag == 1) return;
	}
	tt--;
}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d", &U[i], &V[i]);
		ins(U[i], V[i]); ins(V[i], U[i]);
	}
	for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i, 0); 
	
	for(int i = 1; i <= tot; i++)
	{
		if(v[i].size() < e[i].size())
		{
			memset(h, 0, sizeof(h)); K = 1;
			for(int j = 0; j < e[i].size(); j++)
			{
				int E = e[i][j];
				ins(U[E], V[E]);
				ins(V[E], U[E]);
				d[U[E]]++; d[V[E]]++;
			}
			get_ring(v[i][0], 0);
			int id;
			for(int j = 1; j <= len; j++)
				if(d[r[j]] > 2)
				{
					fr = r[j]; id = j;
					to1 = r[j % len + 1];
					to2 = r[j == 1 ? len : j - 1];
					get_path(r[j]);
					break;
				}
				
			puts("YES");
			printf("%d ", tt); for(int j = 1; j <= tt; j++) printf("%d ", ans[j]); puts("");
			
			int p = ans[tt], o;
			tt = 0; o = id;
			while(r[o] != p)
			{
				ans[++tt] = r[o];
				o = o % len + 1;
			}
			ans[++tt] = p;
			printf("%d ", tt); for(int j = 1; j <= tt; j++) printf("%d ", ans[j]); puts("");
			
			tt = 0; o = id;
			while(r[o] != p)
			{
				ans[++tt] = r[o];
				o = (o == 1 ? len : o - 1);
			}
			ans[++tt] = p;
			printf("%d ", tt); for(int j = 1; j <= tt; j++) printf("%d ", ans[j]); puts("");
			return 0;
		}
	}
	puts("NO");
}