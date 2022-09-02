#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 500000, maxm = 500000, maxq = 500000, maxk = 50;
const int max0 = 3e6;

int n, m, k, q;

pair<int, int> ed[maxm + 5], op[maxm + 5];
bool result[maxm + 5];

int fa[maxk + 5][maxn + 5];
short rk[maxk + 5][maxn + 5];
int dis[maxk + 5][maxn + 5];

pair<pair<int, int>, int> stk_fa[max0 + 5];
int fa_tot = 0;
pair<pair<int, int>, int> stk_rk[max0 + 5];
int rk_tot = 0;
pair<pair<int, int>, int> stk_dis[max0 + 5];
int dis_tot = 0;

inline void back(const int &fap, const int &rkp, const int &disp)
{
	while (fa_tot > fap) --fa_tot, fa[stk_fa[fa_tot].x.x][stk_fa[fa_tot].x.y] = stk_fa[fa_tot].y;
	while (rk_tot > rkp) --rk_tot, rk[stk_rk[rk_tot].x.x][stk_rk[rk_tot].x.y] = stk_rk[rk_tot].y;
	while (dis_tot > disp) --dis_tot, dis[stk_dis[dis_tot].x.x][stk_dis[dis_tot].x.y] = stk_dis[dis_tot].y;
}

inline void change_fa(const int &col, const int &x, const int &y)
{
	stk_fa[fa_tot++] = mp(mp(col, x), fa[col][x]);
	fa[col][x] = y;
}

inline void change_rk(const int &col, const int &x, const int &y)
{
	stk_rk[rk_tot++] = mp(mp(col, x), rk[col][x]);
	rk[col][x] = y;
}

inline void change_dis(const int &col, const int &x, const int &y)
{
	stk_dis[dis_tot++] = mp(mp(col, x), dis[col][x]);
	dis[col][x] = y;
}

int get(const int &col, const int &x)
{
	if (fa[col][x] == x) return x;
	int tmp = get(col, fa[col][x]);
	change_dis(col, x, dis[col][x] ^ dis[col][fa[col][x]]);
	change_fa(col, x, tmp);
	return tmp;
}

bool Union(const int &col, int x, int y)
{
	int u = get(col, x), v = get(col, y);
	if (u == v)
	{
		if ((dis[col][x] ^ dis[col][y]) == 0) return 0;
		return 1;
	}
	if (rk[u] < rk[v]) swap(u, v), swap(x, y);
	change_fa(col, v, u);
	change_dis(col, v, dis[col][x] ^ dis[col][y] ^ 1);
	if (rk[col][u] == rk[col][v]) change_rk(col, u, rk[col][u] + 1);
	return 1;
}

int now[maxm + 5];

int cnt[maxm + 5];

inline void doit(const int &l, const int &r)
{
	REP(i, l, r)
		if (!--cnt[op[i].x])
			if (now[op[i].x] != -1) assert(Union(now[op[i].x], ed[op[i].x].x, ed[op[i].x].y));
}

inline void redoit(const int &l, const int &r)
{
	REP(i, l, r) ++cnt[op[i].x];
}

void work(const int &l, const int &r)
{
	int now_fa = fa_tot;
	int now_rk = rk_tot;
	int now_dis = dis_tot;
	if (r - l <= 1)
	{
		result[l] = Union(op[l].y, ed[op[l].x].x, ed[op[l].x].y);
		if (result[l]) now[op[l].x] = op[l].y;
		back(now_fa, now_rk, now_dis);
	}
	else
	{
		int mid = (l + r) >> 1;
		doit(mid, r);
		work(l, mid);
		back(now_fa, now_rk, now_dis);
		redoit(mid, r);
		doit(l, mid);
		work(mid, r);
		back(now_fa, now_rk, now_dis);
		redoit(l, mid);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d%d", &n, &m, &k, &q);
	REP(i, 0, m) scanf("%d%d", &ed[i].x, &ed[i].y), --ed[i].x, --ed[i].y;
	REP(i, 0, q) scanf("%d%d", &op[i].x, &op[i].y), --op[i].x, --op[i].y, ++cnt[op[i].x];
	REP(j, 0, k) REP(i, 0, n) fa[j][i] = i, rk[j][i] = 0, dis[j][i] = 0;
	memset(now, -1, sizeof now);
	REP(i, 0, q) result[i] = 1; 
	work(0, q);
	REP(i, 0, q) puts(result[i] ? "YES" : "NO");
	return 0;
}