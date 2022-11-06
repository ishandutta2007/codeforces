#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

int h[401000], nxt[401000], to[401000], K = 0;
int tot = 0;
int ch[401000][37], son[401000], siz[401000];
int q[401000], hh = 0, tt = 0;
int Ans[401000], Ans2[401000]; char aans[50100][10]; int _ans[50100];
int fail[401000];
char s1[10100][10], s2[50100][10];

std::vector<int> v[401000], id[401000];

void INS(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

int get(char c)
{
	if(c >= '0' && c <= '9') return c - '0';
	if(c >= 'a' && c <= 'z') return c - 'a' + 10;
	return 26 + 10;
}

void build(char *s, int o)
{
	int len = strlen(s);
	int now = 0;
	for(int i = 0; i < len; i++)
	{
		if(!ch[now][get(s[i])]) ch[now][get(s[i])] = ++tot;
		now = ch[now][get(s[i])];
	}
	id[now].push_back(o);
}

void build_AC()
{
	q[tt++] = 0;
	while(hh < tt)
	{
		int u = q[hh++];
		for(int i = 0; i <= 36; i++)
		{
			if(!ch[u][i]) continue;
			int now = fail[u];
			while(now && !ch[now][i]) now = fail[now];
			int y = ch[now][i];
			if(y != ch[u][i]) fail[ch[u][i]] = y;
			else fail[ch[u][i]] = 0;
			INS(fail[ch[u][i]], ch[u][i]);
			q[tt++] = ch[u][i];
		}
	}
}

void solve(char *s, int o)
{
	int now = 0;
	int len = strlen(s);
	for(int i = 0; i < len; i++)
	{
		while(now && !ch[now][get(s[i])]) now = fail[now];
		now = ch[now][get(s[i])];
		v[now].push_back(o);
	}
}

void dfs1(int x)
{
	siz[x] = 1 + v[x].size();
	for(int i = h[x]; i; i = nxt[i])
	{
		dfs1(to[i]);
		siz[x] += siz[to[i]];
		if(siz[to[i]] > siz[son[x]]) son[x] = to[i];
	}
}

int ans, cnt[401000], ans2;
void ins(int x) {if(cnt[x] == 0) ans++, ans2 = x; cnt[x]++;}
void del(int x) {if(cnt[x] == 1) ans--; cnt[x]--;}

void add(int x, int type, bool w)
{
	int S = v[x].size();
	for(int i = 0; i < S; i++)
		if(!type)
			del(v[x][i]);
		else
			ins(v[x][i]);
	for(int i = h[x]; i; i = nxt[i])
	{
		if(w && to[i] == son[x]) continue;
		add(to[i], type, 0);
	}
}

void dfs(int x, int k)
{
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] != son[x])
			dfs(to[i], 0);
	}
	if(son[x]) dfs(son[x], 1);
	ans = Ans[son[x]]; ans2 = Ans2[son[x]];
	add(x, 1, 1);
	Ans[x] = ans; Ans2[x] = ans2;
	if(!k) add(x, 0, 0);
}

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", s1[i]);
	}
	int m; scanf("%d", &m);
	for(int i = 1; i <= m; i++)
	{
		scanf("%s", s2[i]);
		build(s2[i], i);
	}
	build_AC();
	for(int i = 1; i <= n; i++)
	{
		solve(s1[i], i);
	}
	dfs1(0);
	dfs(0, 1);
	for(int i = 1; i <= tot; i++)
	{
		int S = id[i].size();
		for(int j = 0; j < S; j++)
		{
			_ans[id[i][j]] = Ans[i];
			memcpy(aans[id[i][j]] ,s1[Ans2[i]], sizeof(aans[id[i][j]]));
		}
		
	}
	for(int i = 1; i <= m; i++)
	{
		if(!_ans[i]) printf("0 -\n");
		else printf("%d %s\n", _ans[i], aans[i]);
	}
	return 0;
}