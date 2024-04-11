#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define MN 401000

int ch[MN][26], fa[MN], Max[MN], lst = 1, tot = 1;
int h[MN], nxt[MN], to[MN], K = 0;
int w[MN], st[MN], top = 0, f[MN];
int sum[MN * 40], ls[MN * 40], rs[MN * 40], rt[MN];
int n, ans = 0;
char c[MN];

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void extend(int c)
{
	int u = ++tot, v = lst;
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

int merge(int rt1, int rt2, int l, int r)
{
	if(!rt1) return rt2;
	if(!rt2) return rt1;
	int rt = ++tot; 
	if(l == r) {sum[rt] = sum[rt1] + sum[rt2]; return rt;} 
	int mid = l + r >> 1;
	ls[rt] = merge(ls[rt1], ls[rt2], l, mid);
	rs[rt] = merge(rs[rt1], rs[rt2], mid + 1, r);
	sum[rt] = sum[ls[rt]] + sum[rs[rt]];
	return rt;
}

void modify(int x, int l, int r, int k)
{
	if(l == k && r == k) {sum[x] = 1; return;}
	int mid = l + r >> 1;
	if(k <= mid) ls[x] = ++tot, modify(ls[x], l, mid, k);
	else rs[x] = ++tot, modify(rs[x], mid + 1, r, k);
	sum[x] = sum[ls[x]] + sum[rs[x]];
}

int query(int x, int l, int r, int L, int R)
{
	if(l == L && r == R) return sum[x];
	int mid = l + r >> 1;
	if(R <= mid) return query(ls[x], l, mid, L, R);
	else if(L > mid) return query(rs[x], mid + 1, r, L, R);
	else return query(ls[x], l, mid, L, mid) + query(rs[x], mid + 1, r, mid + 1, R);
}

void dfs1(int x)
{ 
	if(w[x]) rt[x] = ++tot, modify(rt[x], 1, n, w[x]);
	for(int i = h[x]; i; i = nxt[i])
	{
		dfs1(to[i]);
		rt[x] = merge(rt[x], rt[to[i]], 1, n);
		w[x] = w[to[i]];
	}
}

void dfs2(int x)
{
	if(x == 1) st[++top] = x;
	else if(st[top] == 1 || query(rt[st[top]], 1, n, w[x] - Max[x] + Max[st[top]], w[x] - 1)) f[x] = f[st[top]] + 1, st[++top] = x, ans = std::max(ans, f[x]);
	else f[x] = f[st[top]];
	for(int i = h[x]; i; i = nxt[i]) dfs2(to[i]);
	if(st[top] == x) top--;
}

int main()
{
	scanf("%d%s", &n, c + 1);
	for(int i = 1; i <= n; i++) extend(c[i] - 'a'), w[lst] = i;
	for(int i = 2; i <= tot; i++) ins(fa[i], i);
	dfs1(1); dfs2(1);
	printf("%d\n", ans); 
}