#include <iostream>
#include <cstdio>
#include <vector>
#define MN 501000
#define MK 52

typedef std::pair<int, int> P;
int fa[MK][MN], siz[MK][MN], d[MK][MN];
int u[MN], v[MN], e[MN], c[MN];
std::vector<P> a[MN * 4], b[MN * 4];
int col[MN], nxt[MN], Ans[MN], lst[MN];
int n, m, k, q; 

int Find(int c, int x, int &len)
{
	if(fa[c][x] == x) return x;
	len ^= d[c][x];
	return Find(c, fa[c][x], len);
}

int merge(int c, int x, int y)
{
	int len = 0;
	int dx = Find(c, x, len), dy = Find(c, y, len);
	if(dx == dy)
	{
		if(!len) return -1;
		return 0;
	}
	if(siz[c][dx] > siz[c][dy]) std::swap(dx, dy);
	fa[c][dx] = dy; siz[c][dy] += dx; d[c][dx] = len ^ 1;
	return dx;
}

void split(int c, int x)
{
	siz[c][fa[c][x]] -= siz[c][x];
	fa[c][x] = x;
}

void insert(int x, int l, int r, int L, int R, int c, int k)
{
	if(L > R) return;
	if(l == L && r == R) {a[x].push_back(P(c, k)); return;}
	int mid = l + r >> 1;
	if(R <= mid) insert(x << 1, l, mid, L, R, c, k);
	else if(L > mid) insert(x << 1 | 1, mid + 1, r, L, R, c, k);
	else insert(x << 1, l, mid, L, mid, c, k), insert(x << 1 | 1, mid + 1, r, mid + 1, R, c, k); 
}

void solve(int x, int l, int r)
{
	for(int i = 0; i < a[x].size(); i++) b[x].push_back(P(a[x][i].first, merge(a[x][i].first, u[a[x][i].second], v[a[x][i].second])));
	if(l == r)
	{
		int o = merge(c[l], u[e[l]], v[e[l]]);
		if(o != -1) col[e[l]] = c[l], Ans[l] = 1;
		if(col[e[l]]) insert(1, 1, q, l + 1, nxt[l] - 1, col[e[l]], e[l]);
		b[x].push_back(P(c[l], o));
	}
	int mid = l + r >> 1;
	if(l != r) solve(x << 1, l, mid), solve(x << 1 | 1, mid + 1, r);
	for(int i = b[x].size() - 1; i >= 0; i--) if(b[x][i].second > 0) split(b[x][i].first, b[x][i].second);
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for(int i = 1; i <= k; i++)
		for(int j = 1; j <= n; j++)
			fa[i][j] = j, siz[i][j] = 1;
	for(int i = 1; i <= m; i++) scanf("%d%d", &u[i], &v[i]);
	for(int i = 1; i <= q; i++)
	{
		scanf("%d%d", &e[i], &c[i]);
		nxt[lst[e[i]]] = i; lst[e[i]] = i;
	}
	for(int i = 1; i <= m; i++) nxt[lst[i]] = q + 1;
	solve(1, 1, q);
	for(int i = 1; i <= q; i++) if(Ans[i]) puts("YES"); else puts("NO");
}