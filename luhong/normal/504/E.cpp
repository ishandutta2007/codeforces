#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define MN 1201000

int ch[MN][26], fa[MN], Max[MN], lst = 1, tot = 1;
int Min[MN * 2][22], f[MN * 2], tt = 0, b[MN * 2];
int dep[MN], siz[MN], son[MN], top[MN], _fa[MN];
int L[MN], R[MN], oo = 0;
int curs[MN], curt[MN], o1 = 0, s[MN], t[MN], o = 0, s2[MN], t2[MN], o2 = 0;
std::vector<int> v[MN];
int w1[MN], w2[MN], dfn[MN], rdfn[MN], D = 0;
char c[MN];
int h[MN], nxt[2 * MN], to[2 * MN], K = 0;

int Abs(int x) {return x > 0 ? x : -x;}

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void extend(int c)
{
	int u = ch[lst][c] ? 0 : ++tot, v = lst;
	while(v && !ch[v][c]) ch[v][c] = u, v = fa[v];
	int o = ch[v][c];
	if(!v) fa[u] = 1;
	else if(Max[o] == Max[v] + 1) fa[u] = o;
	else
	{
		int n = ++tot; Max[n] = Max[v] + 1;
		while(ch[v][c] == o) ch[v][c] = n, v = fa[v];
		fa[n] = fa[o]; fa[o] = n; fa[u] = n;
		memcpy(ch[n], ch[o], sizeof(ch[o]));
	}
	Max[u] = Max[lst] + 1;
	lst = ch[lst][c];
}

void dfs1(int x)
{
	
	f[x] = ++tt; Min[tt][0] = Max[x];
	for(int i = 0; i < v[x].size(); i++)
		dfs1(v[x][i]), Min[++tt][0] = Max[x];
}

int LCP(int x, int y)
{
	int l = f[x], r = f[y];
	if(l > r) std::swap(l, r);
	int len = r - l + 1;
	return std::min(Min[l][b[len]], Min[r - (1 << b[len]) + 1][b[len]]);
}

void dfs2(int x)
{
	siz[x] = 1;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == _fa[x]) continue;
		dep[to[i]] = dep[x] + 1;
		_fa[to[i]] = x; 
		dfs2(to[i]);
		siz[x] += siz[to[i]];
		if(siz[to[i]] > siz[son[x]]) son[x] = to[i];
	}
}

void dfs3(int x, int tp)
{
	top[x] = tp; dfn[x] = ++D; rdfn[D] = x; 
	if(son[x]) dfs3(son[x], tp);
	else {++oo; L[oo] = dfn[top[x]]; R[oo] = dfn[x];}
	for(int i = h[x]; i; i = nxt[i])
		if(to[i] != _fa[x] && to[i] != son[x]) dfs3(to[i], to[i]);
}

void path(int u, int v)
{
	o1 = o = 0;
	while(top[u] != top[v])
	{
		if(dep[top[u]] > dep[top[v]])
		{
			++o; s[o] = dfn[u], t[o] = dfn[top[u]];
			u = _fa[top[u]];
		}
		else
		{
			++o1; curs[o1] = dfn[top[v]], curt[o1] = dfn[v];
			v = _fa[top[v]];
		}
	}
	++o, s[o] = dfn[u], t[o] = dfn[v];
	for(int i = o1; i >= 1; i--) ++o, s[o] = curs[i], t[o] = curt[i];
}

int main()
{
	int n, q; scanf("%d%s", &n, c + 1);
	for(int i = 1; i < n; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		ins(u, v); ins(v, u);
	}
	dfs2(1); dfs3(1, 1);
	for(int i = 1; i <= oo; i++) 
	{
		lst = 1;
		for(int j = L[i]; j <= R[i]; j++)
			extend(c[rdfn[j]] - 'a'), w1[j] = lst;
		lst = 1;
		for(int j = R[i]; j >= L[i]; j--)
			extend(c[rdfn[j]] - 'a'), w2[j] = lst;
	}
	for(int i = 2; i <= tot; i++) v[fa[i]].push_back(i);
	dfs1(1);
	for(int i = 1; i <= 21; i++)
		for(int j = 1; j + (1 << i) - 1 <= tt; j++)
			Min[j][i] = std::min(Min[j][i - 1], Min[j + (1 << i - 1)][i - 1]);
	b[0] = -1; for(int i = 1; i <= tt; i++) b[i] = b[i >> 1] + 1;
	scanf("%d", &q);
	for(int i = 1; i <= q; i++)
	{
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
		path(a, b);
		for(int j = 1; j <= o; j++) s2[j] = s[j], t2[j] = t[j]; o2 = o;
		path(c, d);
		int j = 1, k = 1, ans = 0;
		while(j <= o && k <= o2)
		{
			int len = std::min(Abs(s[j] - t[j]), Abs(s2[k] - t2[k])) + 1;
			int p, q; 
			if(s[j] < t[j]) p = w2[s[j]];
			else p = w1[s[j]];
			if(s2[k] < t2[k]) q = w2[s2[k]];
			else q = w1[s2[k]];
			int lcp = std::min(len, LCP(p, q)); ans += lcp;
			if(lcp < len) break; 
			if(Abs(s[j] - t[j]) + 1 == len) j++;
			else if(s[j] < t[j]) s[j] += len;
			else s[j] -= len;
			if(Abs(s2[k] - t2[k]) + 1 == len) k++;
			else if(s2[k] < t2[k]) s2[k] += len;
			else s2[k] -= len;
		}
		printf("%d\n", ans);
	}
}