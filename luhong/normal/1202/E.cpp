#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MN 401000

char t[MN], s[MN];
int ans1[MN], ans2[MN];
std::vector<char> c[MN];

int ch[MN][26], fail[MN], tot = 1;
int h[MN], nxt[MN], to[MN], K = 0;
int v[MN], q[MN];

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void build(char *s, int w)
{
	int len = strlen(s), now = 1;
	for(int i = 0; i < len; i++)
	{
		if(!ch[now][s[i] - 'a']) ch[now][s[i] - 'a'] = ++tot;
		now = ch[now][s[i] - 'a'];
	}
	v[now] += w;
}

void build_AC()
{
	int h = 0, t = 0;
	for(int i = 0; i < 26; i++)
	{
		if(ch[1][i]) q[t++] = ch[1][i], fail[ch[1][i]] = 1, ins(fail[ch[1][i]], ch[1][i]);
		else ch[1][i] = 1;
	}
	
	while(h < t)
	{
		int u = q[h++];
		for(int i = 0; i < 26; i++)
		{
			if(ch[u][i])
			{
				fail[ch[u][i]] = ch[fail[u]][i];
				ins(fail[ch[u][i]], ch[u][i]);
				q[t++] = ch[u][i];
			}
			else ch[u][i] = ch[fail[u]][i];
		}
	}
}

void dfs(int x)
{
	for(int i = h[x]; i; i = nxt[i])
	{
		v[to[i]] += v[x];
		dfs(to[i]);
	}
}

int main()
{
	scanf("%s", t); build(t, 0);
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", s); int len = strlen(s);
		for(int j = 0; j < len; j++) c[i].push_back(s[j]);
		build(s, 1);
	}
	build_AC(); dfs(1);
	int len = strlen(t), now = 1;
	for(int i = 0; i < len; i++)
	{
		now = ch[now][t[i] - 'a'];
		ans1[i + 1] = v[now];
	}
	
	memset(ch, 0, sizeof(ch)); tot = 1;
	memset(fail, 0, sizeof(fail));
	memset(h, 0, sizeof(h)); K = 0;
	memset(v, 0, sizeof(v));
	
	std::reverse(t, t + len);
	build(t, 0);
	for(int i = 1; i <= n; i++)
	{
		for(int j = (int)c[i].size() - 1; j >= 0; j--) s[c[i].size() - j - 1] = c[i][j];
		s[c[i].size()] = '\0';
		build(s, 1);
	}
	build_AC(); dfs(1);
	now = 1;
	for(int i = 0; i < len; i++)
	{
		now = ch[now][t[i] - 'a'];
		ans2[i + 1] = v[now];
	}
	
	long long Ans = 0;
	for(int i = 1; i <= len; i++) Ans = Ans + 1ll * ans1[i] * ans2[len - i];
	printf("%lld\n", Ans);
}