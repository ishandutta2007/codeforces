#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define MN 1101000

struct Query{
	int l, r, id;
};

std::vector<int> v[MN];
std::vector<Query> q[MN];

int fa[MN], Max[MN], w[MN], ch[MN][26];
int st[MN][22], rt[MN], tot = 1;
int h[MN], nxt[2 * MN], to[2 * MN], K = 0;
int lst = 1, m, Ans1[MN], Ans2[MN];
struct xxx{
	int Max, id;
}t[MN * 22];
int ls[MN * 22], rs[MN * 22], tot2 = 0;
char s[MN];

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void extend(int s)
{
	if(ch[lst][s])
	{
		int v = lst, o = ch[v][s];
		if(Max[o] == Max[v] + 1) lst = o;
		else
		{
			int n = ++tot; Max[n] = Max[v] + 1;
			while(ch[v][s] == o) ch[v][s] = n, v = fa[v];
			fa[n] = fa[o]; fa[o] = n; 
			memcpy(ch[n], ch[o], sizeof(ch[o]));
			lst = n;
		}
		return;
	}
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

xxx operator + (xxx a, xxx b)
{
	xxx c;
	c.id = (a.Max >= b.Max ? a.id : b.id);
	c.Max = std::max(a.Max, b.Max); 
	return c;
}

int merge(int rt1, int rt2, int l, int r)
{
	if(!rt1) return rt2;
	if(!rt2) return rt1;
	if(l == r)
	{
		t[rt1].Max += t[rt2].Max;
		return rt1;
	}
	int mid = l + r >> 1;
	ls[rt1] = merge(ls[rt1], ls[rt2], l, mid);
	rs[rt1] = merge(rs[rt1], rs[rt2], mid + 1, r);
	t[rt1] = t[ls[rt1]] + t[rs[rt1]];
	return rt1;
}

void modify(int x, int l, int r, int k)
{
	if(l == k && r == k) {t[x].Max++; t[x].id = l; return;}
	int mid = l + r >> 1;
	if(k <= mid)
	{
		if(!ls[x]) ls[x] = ++tot2;
		modify(ls[x], l, mid, k);
	}
	else
	{
		if(!rs[x]) rs[x] = ++tot2;
		modify(rs[x], mid + 1, r, k);
	}
	t[x] = t[ls[x]] + t[rs[x]]; 
}

xxx query(int x, int l, int r, int L, int R)
{
	if(l == L && r == R) return t[x];
	int mid = l + r >> 1;
	if(R <= mid) return query(ls[x], l, mid, L, R);
	else if(L > mid) return query(rs[x], mid + 1, r, L, R);
	else return query(ls[x], l, mid, L, mid) + query(rs[x], mid + 1, r, mid + 1, R);
}

int Find(int x, int k)
{
	for(int i = 20; i >= 0; i--)
		if(Max[st[x][i]] >= k) x = st[x][i];
	return x;
}

void dfs1(int x)
{
	st[x][0] = fa[x];
	for(int i = 1; i <= 20; i++) st[x][i] = st[st[x][i - 1]][i - 1];
	
	for(int i = h[x]; i; i = nxt[i]) dfs1(to[i]);
}

void dfs2(int x)
{
	for(int i = 0; i < v[x].size(); i++) 
	{
		if(!rt[x]) rt[x] = ++tot2;
		modify(rt[x], 1, m, v[x][i]);
	}
	for(int i = h[x]; i; i = nxt[i])
	{
		dfs2(to[i]);
		rt[x] = merge(rt[x], rt[to[i]], 1, m);
	}
	for(int i = 0; i < q[x].size(); i++)
	{
		xxx p = query(rt[x], 1, m, q[x][i].l, q[x][i].r);
		if(p.Max == 0) p.id = q[x][i].l;
		Ans1[q[x][i].id] = p.Max; 
		Ans2[q[x][i].id] = p.id;
	}
}

int main()
{
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	for(int i = 1; i <= len; i++)
	{
		extend(s[i] - 'a');
		w[i] = lst;
	}
	
	scanf("%d", &m);
	for(int i = 1; i <= m; i++)
	{
		lst = 1;
		scanf("%s", s + 1);
		len = strlen(s + 1);
		for(int j = 1; j <= len; j++)
		{
			extend(s[j] - 'a');
			v[lst].push_back(i); 
		}
	}
	
	for(int i = 2; i <= tot; i++) ins(fa[i], i);
	
	dfs1(1);
	int T; scanf("%d", &T);
	for(int i = 1; i <= T; i++)
	{
		int l, r, a, b; scanf("%d%d%d%d", &l, &r, &a, &b);
		int x = Find(w[b], b - a + 1); 
		Query Q; Q.id = i; Q.l = l; Q.r = r;
		q[x].push_back(Q);
	}
	dfs2(1);
	for(int i = 1; i <= T; i++) printf("%d %d\n", Ans2[i], Ans1[i]);
}