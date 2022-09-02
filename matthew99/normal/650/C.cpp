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

const int maxn = 1000000;

int n, m;

vector<int> a[maxn + 5];
vector<int> ans[maxn + 5];

vector<pair<int, int> > all;

inline bool cmp(const pair<int, int> &x, const pair<int, int> &y)
{
	return a[x.x][x.y] < a[y.x][y.y];
}

inline bool cmp0(const pair<int, int> &x, const pair<int, int> &y)
{
	return x.x < y.x;
}

inline bool cmp1(const pair<int, int> &x, const pair<int, int> &y)
{
	return x.y < y.y;
}

int Maxcol[maxn + 5], Maxrow[maxn + 5];

int fa[maxn + 5];

inline int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n)
	{
		a[i].resize(m);
		ans[i].resize(m);
		REP(j, 0, m) scanf("%d", &a[i][j]), all.pb(mp(i, j));
	}
	REP(i, 0, n * m) fa[i] = i;
	sort(ALL(all), cmp);
	memset(Maxrow, 0, sizeof Maxrow);
	memset(Maxcol, 0, sizeof Maxcol);
	static int val[maxn + 5];
	memset(val, 0, sizeof val);
	for (int i = 0; i < SZ(all); )
	{
		int j = i;
		while (j < SZ(all) && a[all[j].x][all[j].y] == a[all[i].x][all[i].y]) ++j;
		sort(all.begin() + i, all.begin() + j, cmp0);
		REP(k, i, j - 1) if (all[k + 1].x == all[k].x) fa[get(all[k + 1].x * m + all[k + 1].y)] = get(all[k].x * m + all[k].y);
		sort(all.begin() + i, all.begin() + j, cmp1);
		REP(k, i, j - 1) if (all[k + 1].y == all[k].y) fa[get(all[k + 1].x * m + all[k + 1].y)] = get(all[k].x * m + all[k].y);
		REP(k, i, j) chkmax(val[get(all[k].x * m + all[k].y)], max(Maxrow[all[k].x], Maxcol[all[k].y]));
		REP(k, i, j) ans[all[k].x][all[k].y] = val[get(all[k].x * m + all[k].y)];
		REP(k, i, j)
		{
			chkmax(Maxrow[all[k].x], ans[all[k].x][all[k].y] + 1);
			chkmax(Maxcol[all[k].y], ans[all[k].x][all[k].y] + 1);
		}
		i = j;
	}
	REP(i, 0, n)
	{
		REP(j, 0, m) printf("%d ", ans[i][j] + 1);
		printf("\n");
	}
	return 0;
}