#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define MN 100010

const int inf = 1e8;
int h[MN], nxt[2 * MN], to[2 * MN], cost[2 * MN], K = 0;
int s1[MN * 150], s2[MN * 150], ls[MN * 150], rs[MN * 150], rt[MN], tot = 0;
int Max[MN], A[MN], B[MN];
int st[MN], top = 0;

void ins(int u, int v, int c) {nxt[++K] = h[u]; h[u] = K; to[K] = v; cost[K] = c;}

int merge(int x, int y, int l, int r)
{
	if(!x) return y;
	if(!y) return x;
	if(l == r) {s1[x] += s1[y]; s2[x] += s2[y]; return x;} 
	int mid = l + r >> 1;
	ls[x] = merge(ls[x], ls[y], l, mid);
	rs[x] = merge(rs[x], rs[y], mid + 1, r);
	s1[x] = s1[ls[x]] + s1[rs[x]]; s2[x] = s2[ls[x]] + s2[rs[x]];
	if(top < MN) {st[++top] = y; s1[y] = s2[y] = ls[y] = rs[y] = 0;} 
	return x;
}

int newnode()
{
	if(!top) st[++top] = ++tot;
	return st[top--];
}

int modify(int o, int l, int r, int k, int t)
{
	int x = newnode(); 
	if(l == k && r == k) {s1[x] = s1[o] + t; s2[x] += s2[o] + t * k; if(!s1[x] && top < MN) {st[++top] = x; return 0;} return x;}
	int mid = l + r >> 1; ls[x] = ls[o]; rs[x] = rs[o];
	if(k <= mid) ls[x] = modify(ls[o], l, mid, k, t);
	else rs[x] = modify(rs[o], mid + 1, r, k, t);
	s1[x] = s1[ls[x]] + s1[rs[x]]; s2[x] = s2[ls[x]] + s2[rs[x]];
	if(!s1[x] && top < MN) {st[++top] = x; ls[x] = rs[x] = 0; return 0;} 
	return x;
}

int query2(int x, int l, int r, int s)
{
	if(!x) return 0;
	if(l == r) return l;
	int mid = l + r >> 1;
	if(s1[rs[x]] < s) return query2(ls[x], l, mid, s - s1[rs[x]]);
	else return query2(rs[x], mid + 1, r, s);
}

int query(int x, int l, int r, int s)
{
	if(!x) return 0;
	if(l == r) return std::min(s2[x], l * s);
	int mid = l + r >> 1;
	if(s1[rs[x]] < s) return query(ls[x], l, mid, s - s1[rs[x]]) + s2[rs[x]];
	else return query(rs[x], mid + 1, r, s);
}

void dfs1(int x, int fa)
{
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == fa) continue;
		dfs1(to[i], x);
		int k = query(rt[to[i]], 1, inf, 1);
		rt[x] = merge(rt[x], rt[to[i]], 1, inf);
		
		if(k) rt[x] = modify(rt[x], 1, inf, k, -1);
		rt[x] = modify(rt[x], 1, inf, k + cost[i], 1);
	}
	Max[x] = query(rt[x], 1, inf, 1);
}

void dfs2(int x, int fa)
{
	int M = 0, cM = 0;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(Max[to[i]] + cost[i] > M) cM = M, M = Max[to[i]] + cost[i];
		else cM = std::max(cM, Max[to[i]] + cost[i]);
	}
	A[x] = M; B[x] = cM;
	int oo = Max[x];
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == fa) continue;
		rt[to[i]] = rt[x];
		
		rt[to[i]] = modify(rt[to[i]], 1, inf, Max[to[i]] + cost[i], -1);
		if(Max[to[i]]) rt[to[i]] = modify(rt[to[i]], 1, inf, Max[to[i]], 1);
		
		int k = M;
		if(M == Max[to[i]] + cost[i]) k = cM;
		
		if(k) rt[to[i]] = modify(rt[to[i]], 1, inf, k, -1);
		rt[to[i]] = modify(rt[to[i]], 1, inf, k + cost[i], 1);
		
		Max[x] = k;
		dfs2(to[i], x);
	}
	Max[x] = oo;
}

int main()
{
	int n, q; scanf("%d%d", &n, &q);
	for(int i = 1; i < n; i++)
	{
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		ins(a, b, c); ins(b, a, c);
	}
	dfs1(1, 0); dfs2(1, 0);
	int ans = 0;
	for(int i = 1; i <= q; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		x = (x + ans - 1) % n + 1;
		y = (y + ans - 1) % n + 1;
		y--;
		int w; 
		if(query2(rt[x], 1, inf, 2 * y) > A[x]) ans = query(rt[x], 1, inf, 2 * y) + A[x] + B[x];
		else if(query2(rt[x], 1, inf, 2 * y + 1) > B[x]) ans = query(rt[x], 1, inf, 2 * y + 1) + B[x];
		else ans = query(rt[x], 1, inf, 2 * y + 2);
		printf("%d\n", ans);
	}
}