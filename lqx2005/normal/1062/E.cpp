#include<bits/stdc++.h>
#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define mpr make_pair
#define x(v) (v).first
#define y(v) (v).second
#define siz(v) (int)(v).size()
#define pb push_back
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef double db;
const int N = 2e5 + 10;
const int Log = 20;
struct edge
{
	int to, nxt;
}e[N << 1];
int head[N], tot = 0;
int n, q;
int seq[N], fir[N], dfn[N], mp[N], dfc, cnt = 0, dep[N];
int p2[Log + 5], l2[N], st[Log + 5][N], sl[Log + 5][N];
void adde(int u, int v){e[++tot] = edge{v, head[u]}, head[u] = tot;}

void dfs(int u, int fa)
{
	int p = ++dfc;
	dep[u] = dep[fa] + 1;
	seq[++cnt] = p;
	fir[u] = cnt;
	dfn[u] = p, mp[p] = u;
	for(int i = head[u]; i; i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs(v, u);
		seq[++cnt] = p;
	}
	return;
}

void initst(int n)
{
	p2[0] = 1;
	for(int i = 1; i <= Log; i++) p2[i] = p2[i - 1] << 1;
	l2[0] = -1;
	for(int i = 1; i <= n; i++) l2[i] = l2[i >> 1] + 1;
	for(int i = 1; i <= n; i++) st[0][i] = seq[i];
	for(int i = 1; i <= l2[n]; i++)
	{
		for(int j = 1; j + p2[i] - 1 <= n; j++)
		{
			st[i][j] = min(st[i - 1][j], st[i - 1][j + p2[i - 1]]);
		}
	}
	return;
}

int quer(int l, int r)
{
	if(l > r) return -1;
	int t = r - l + 1;
	t = l2[t];
	return min(st[t][l], st[t][r - p2[t] + 1]);
}

int lca(int u, int v)
{
	if(u == 0 || v == 0) return u + v;
	if(dfn[u] > dfn[v]) swap(u, v);
	int q = quer(fir[u], fir[v]);
	return mp[q];
}

int que(int l, int r)
{
	if(l > r) return 0;
	int t = r - l + 1;
	t = l2[t];
	return lca(sl[t][l], sl[t][r - p2[t] + 1]);
}

void initlca(int n)
{
	for(int i = 1; i <= n; i++) sl[0][i] = i;
	for(int i = 1; i <= l2[n]; i++)
	{
		for(int j = 1; j + p2[i] - 1 <= n; j++)
		{
			sl[i][j] = lca(sl[i - 1][j], sl[i - 1][j + p2[i - 1]]);
		}
	}
	return;
}

int query(int l, int r)
{
	if(l + 1 == r)
	{
		if(dep[l] > dep[r]) return r;
		return l;
	}
	int mx = que(l, r);
	if(que(l + 1, r) != mx) return l;
	int pos = l, pre = l;
	for(int i = Log; i >= 0; i--)
	{
		if(pos + p2[i] > r) continue;
		int to = que(pos + 1, pos + p2[i]);
		to = lca(pre, to);
		if(to == mx) continue;
		pre = to;
		pos += p2[i];
	}
	return pos + 1;
}



int main()
{
	scanf("%d%d", &n, &q);
	int fa;
	for(int i = 2; i <= n; i++)
	{
		scanf("%d", &fa);
		adde(i, fa), adde(fa, i);
	}
	dep[0] = -1;
	dfs(1, 0);
	initst(cnt);
	initlca(n);
	
	for(int amo = 1; amo <= q; amo++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		int pos = query(l, r);
		int LCA = lca(que(l, pos - 1), que(pos + 1, r));
		printf("%d %d\n", pos, dep[LCA]);
	}
	return 0;
}