#include <bits/stdc++.h>
#define uint unsigncnt long long
#define ll long long
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
using namespace std;
const db pi = acos(-1.0);
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
int n, m;
const int N = 2e5 + 10;

struct SegTree
{
	int sum[N << 2], tag[N << 2];

	void clear()
	{
		memset(sum, 0, sizeof sum);
		memset(tag, 0, sizeof tag);
	}

	void push_down(int rt, int l, int mid, int r)
	{
		if (tag[rt])
		{
			sum[rt << 1] += (mid - l + 1) * tag[rt];
			sum[rt << 1 | 1] += (r - mid) * tag[rt];
			tag[rt << 1] += tag[rt];
			tag[rt << 1 | 1] += tag[rt];
			tag[rt] = 0;
		}
	}

	void update(int rt, int l, int r, int L, int R, int val)
	{
		if (L <= l && r <= R)
		{
			sum[rt] += (r - l + 1) * val;
			tag[rt] += val;
			return;
		}
		int mid = (l + r) >> 1;
		push_down(rt, l, mid, r);
		if (L <= mid) update(rt << 1, l, mid, L, R, val);
		if (mid < R) update(rt << 1 | 1, mid + 1, r, L, R, val);
		sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	}

	int query(int rt, int l, int r, int L, int R)
	{
		if (L <= l && r <= R) return sum[rt];
		int mid = (l + r) >> 1;
		push_down(rt, l, mid, r);
		int res = 0;
		if (L <= mid) res += query(ls, l, mid, L, R);
		if (mid < R) res += query(rs, mid + 1, r, L, R);
		return res;
	}

	int wz(int x) { return query(1, 1, n, x, x); }

	void update(int x, int y) { update(1, 1, n, x, x, y); }
} f, g;

int head[N], nxt[N], to[N], cnt;

void insert(int u, int v)
{
	nxt[++ cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
}

int fa[N], Dep[N], son[N], top[N], dfn[N], dfn1[N], sz[N], tot;

int dfs1(int now)
{
	sz[now] = 1;
	int ms = 0;
	for (int i = head[now]; i; i = nxt[i])
	{
		Dep[to[i]] = Dep[now] + 1;
		int tmp = dfs1(to[i]);
		sz[now] += tmp;
		if (tmp > ms)
		{
			ms = tmp;
			son[now] = to[i];
		}
	}
	return sz[now];
}

void dfs2(int now, int tp)
{
	dfn[now] = ++ tot; 
	dfn1[tot] = now;
	top[now] = tp;
	if (son[now]) dfs2(son[now], tp);
	for (int i = head[now]; i; i = nxt[i])
	{
		if (to[i] == son[now]) continue;
		dfs2(to[i], to[i]);
	}
}

int find_lca(int u, int v)
{
	while (top[u] != top[v])
	{
		if (Dep[top[u]] < Dep[top[v]]) swap(u, v);
		u = fa[top[u]];
	}
	if(Dep[u] < Dep[v]) return u;
	return v;
}

int fs(int u, int Fa)
{
	while (top[u] != top[Fa])
	{
		if (fa[top[u]] == Fa) return top[u];
		u = fa[top[u]];
	}
	return dfn1[dfn[Fa] + 1];
}

struct Query
{
	int u, v, c;

	Query() {}
	Query(int u, int v, int c): u(u), v(v), c(c) {}
};
vector<Query> Q[N];

void dfs3(int now)
{
	int sum = 0;
	for (int i = head[now]; i; i = nxt[i])
	{
		dfs3(to[i]);
		sum += f.wz(dfn[to[i]]);
	}
	int nf = sum;
	for (auto it : Q[now])
	{
		int u = it.u, v = it.v, c = it.c;
		if (u == now) nf = max(nf, sum - f.wz(dfn[fs(v, now)]) + g.wz(dfn[v]) + c);
		else nf = max(nf, sum - f.wz(dfn[fs(u, now)]) - f.wz(dfn[fs(v, now)]) + g.wz(dfn[u]) + g.wz(dfn[v]) + c);
	}
	f.update(dfn[now], nf);
	for (int i = head[now]; i; i = nxt[i])
		g.update(1, 1, n, dfn[to[i]], dfn[to[i]] + sz[to[i]] - 1, sum - f.wz(dfn[to[i]]));
	g.update(dfn[now], sum);
}

int main()
{
	n = read();
	m = read();
	rep(i, 2, n)
	{
		fa[i] = read();
		insert(fa[i], i);
	}
	dfs1(1);
	dfs2(1, 1);
	rep(i, 1, n) Q[i].clear();
	rep(i, 1, m)
	{
		int u = read();
		int v = read();
		int c = read();
		if (dfn[u] > dfn[v]) swap(u, v);
		int lca = find_lca(u, v);
		Q[lca].pb(Query(u, v, c));
	}
	dfs3(1);
	cout << f.wz(dfn[1]);
	return 0;
}