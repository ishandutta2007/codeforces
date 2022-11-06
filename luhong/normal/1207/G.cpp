#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#define MN 801000

int fail[MN], ch[MN][26], tot = 0, CH[MN][26];
int h[MN], nxt[2 * MN], to[2 * MN], K = 0;
int dfn[MN], siz[MN], D = 0;
int c[MN], q[MN];
std::vector<int> v[MN];
std::vector<int> Q[MN];
int Ans[MN], ws[MN], wq[MN];
char s[MN];

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void add(int x, int v) {for(int i = x; i <= D; i += i & -i) c[i] += v;}
int query(int x) {int ans = 0; for(int i = x; i; i -= i & -i) ans = ans + c[i]; return ans;}

void build(char *s, int id)
{
	int now = 0;
	int len = strlen(s);
	for(int i = 0; i < len; i++)
	{
		if(!ch[now][s[i] - 'a']) ch[now][s[i] - 'a'] = ++tot; 
		now = ch[now][s[i] - 'a'];
	}
	wq[id] = now;
}

void build_AC()
{
	int hh = 0, tt = 0;
	for(int i = 0; i < 26; i++)
		if(ch[0][i])
		{
			q[tt++] = ch[0][i];
			ins(0, ch[0][i]); 
			CH[0][i] = ch[0][i];
		}
	
	while(hh < tt)
	{
		int u = q[hh++];
		for(int i = 0; i < 26; i++)
		{
			if(ch[u][i])
			{
				fail[ch[u][i]] = ch[fail[u]][i];
				ins(fail[ch[u][i]], ch[u][i]); 
				q[tt++] = ch[u][i];
				CH[u][i] = ch[u][i];
			}
			else ch[u][i] = ch[fail[u]][i];
		}
	}
}

void dfs1(int x)
{
	dfn[x] = ++D; siz[x] = 1;
	for(int i = h[x]; i; i = nxt[i]) dfs1(to[i]), siz[x] += siz[to[i]];
}

void dfs2(int x)
{
	add(dfn[x], 1);
	for(int i = 0; i < v[x].size(); i++)
		for(int j = 0; j < Q[v[x][i]].size(); j++)
		{
			int y = Q[v[x][i]][j];
			Ans[y] = query(dfn[wq[y]] + siz[wq[y]] - 1) - query(dfn[wq[y]] - 1);
		}
	for(int i = 0; i < 26; i++) if(CH[x][i]) dfs2(CH[x][i]);
	add(dfn[x], -1); 
}


int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int opt, j, now; scanf("%d", &opt);
		char c[2]; 
		if(opt == 1)
		{
			scanf("%s", c);
			now = 0;
		}
		else
		{
			scanf("%d%s", &j, c);
			now = ws[j];
		}
		if(!ch[now][c[0] - 'a']) ch[now][c[0] - 'a'] = ++tot;
		now = ch[now][c[0] - 'a'];
		ws[i] = now; v[now].push_back(i);
	}
	int m; scanf("%d", &m);
	for(int i = 1; i <= m; i++)
	{
		int p; scanf("%d%s", &p, s);
		build(s, i);
		Q[p].push_back(i);
	}
	build_AC();
	dfs1(0); dfs2(0);
	for(int i = 1; i <= m; i++) printf("%d\n", Ans[i]);
}