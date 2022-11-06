#include <cstdio>
#include <iostream>
#include <cstring> 
#define MN 2010
#define mod 1000000007

int n;
int mi[55];
int Max[MN], fa[MN], ch[MN][10], lst = 1, tot = 1;
int trans[MN][10], len[MN][10];
int h[MN], nxt[2 * MN], to[2 * MN], K = 0;
char s[MN], x[55], y[55];
int f[55][MN][55][2][2];
int sl[55], sr[55];

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void extend(int s)
{
	int u = ++tot, v = lst;
	while(v && !ch[v][s]) ch[v][s] = u, v = fa[v];
	int o = ch[v][s];
	if(!v) fa[u] = 1;
	else if(Max[o] == Max[v] + 1) fa[u] = o;
	else
	{
		int n = ++tot; Max[n] = Max[v] + 1; 
		while(ch[v][s] == o) ch[v][s] = n, v = fa[v];
		fa[n] = fa[o]; fa[o] = n; fa[u] = n;
		memcpy(ch[n], ch[o], sizeof(ch[o]));
	}
	Max[u] = Max[lst] + 1;
	lst = u;
}

void dfs(int x)
{
	for(int i = 0; i < 10; i++)
	{
		if(ch[x][i]) trans[x][i] = ch[x][i], len[x][i] = Max[x] + 1;
		else if(x != 1) trans[x][i] = trans[fa[x]][i], len[x][i] = len[fa[x]][i];
		else trans[x][i] = 1, len[x][i] = 0;
	}
	for(int i = h[x]; i; i = nxt[i]) dfs(to[i]);
}

void rw(int &a, int b) {a = (a + b) % mod;}

int DP(int i, int p, int len, int t1, int t2)
{
	if(len >= n / 2)
	{
		int L = 0, R = (mi[n - i + 1] - 1 + mod) % mod;
		if(t1) L = sl[i]; if(t2) R = sr[i];
		return (R - L + 1 + mod) % mod;
	}
	if(i > n) return 0;
	if(f[i][p][len][t1][t2] != -1) return f[i][p][len][t1][t2];
	int &ans = f[i][p][len][t1][t2];
	ans = 0;
	int l = (t1 == 1 ? x[i] - '0' : 0);
	int r = (t2 == 1 ? y[i] - '0' : 9);
	for(int j = l; j <= r; j++)
	{
		if(ch[p][j]) rw(ans, DP(i + 1, ch[p][j], len + 1, t1 & (j == l), t2 & (j == r)));
		else rw(ans, DP(i + 1, trans[p][j], ::len[p][j], t1 & (j == l), t2 & (j == r)));
	}
	return ans;
}

int main()
{
	memset(f, -1, sizeof(f));
	scanf("%s", s); int len = strlen(s);
	for(int i = 0; i < len; i++) extend(s[i] - '0');
	for(int i = 2; i <= tot; i++) ins(fa[i], i);
	dfs(1);
	scanf("%s", x + 1);
	scanf("%s", y + 1);
	n = strlen(x + 1);
	mi[0] = 1; for(int i = 1; i <= n; i++) mi[i] = 10ll * mi[i - 1] % mod;
	for(int i = n; i >= 1; i--)
	{
		sl[i] = (sl[i + 1] + 1ll * mi[n - i] * (x[i] - '0')) % mod;
		sr[i] = (sr[i + 1] + 1ll * mi[n - i] * (y[i] - '0')) % mod;
	}
	printf("%d\n", DP(1, 1, 0, 1, 1));
}