#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 20;

int n, m;
int a[maxn + 5][maxn + 5];

//31
//42

int sum = 0;

vector<vector<int> > ans;

inline void step(int x, int y, int xd, int yd)
{
	sum += 4;
	ans.pb({a[x][y], a[x][y + yd], a[x + xd][y + yd], a[x + xd][y]});
	swap(a[x][y], a[x + xd][y]);
	swap(a[x + xd][y], a[x + xd][y + yd]);
	swap(a[x + xd][y + yd], a[x][y + yd]);
}

inline void rstep(int x, int y, int xd, int yd)
{
	sum += 4;
	ans.pb({a[x][y], a[x + xd][y], a[x + xd][y + yd], a[x][y + yd]});
	swap(a[x][y], a[x][y + yd]);
	swap(a[x][y + yd], a[x + xd][y + yd]);
	swap(a[x + xd][y + yd], a[x + xd][y]);
}

//213
//456

inline void r(int x, int _y)
{
	REP(u, 0, 2)
		REP(v, 0, 2)
		{
			int xd = u ? 1 : -1;
			int yd = v ? 1 : -1;
			int y = _y;
			if (yd == -1)
			{
				y -= yd;
			}
			if (x + xd >= 0 && x + xd < n && y >= 0 && y < m && y + 2 * yd >= 0 && y + 2 * yd < m)
			{
				step(x, y, xd, yd);
				step(x, y + yd, xd, yd);
				sum += 6;
				ans.pb({a[x][y], a[x + xd][y], a[x + xd][y + yd], a[x + xd][y + 2 * yd], a[x][y + 2 * yd], a[x][y + yd]});
				swap(a[x][y], a[x][y + yd]);
				swap(a[x][y + yd], a[x][y + 2 * yd]);
				swap(a[x][y + 2 * yd], a[x + xd][y + 2 * yd]);
				swap(a[x + xd][y + 2 * yd], a[x + xd][y + yd]);
				swap(a[x + xd][y + yd], a[x + xd][y]);
				return;
			}
		}
}

inline void c(int _x, int y)
{
	REP(u, 0, 2)
		REP(v, 0, 2)
		{
			int xd = u ? 1 : -1;
			int yd = v ? 1 : -1;
			int x = _x;
			if (xd == -1)
			{
				x -= xd;
			}
			if (y + yd >= 0 && y + yd < m && x >= 0 && x < n && x + 2 * xd >= 0 && x + 2 * xd < n)
			{
				rstep(x, y, xd, yd);
				rstep(x + xd, y, xd, yd);
				sum += 6;
				ans.pb({a[x][y], a[x][y + yd], a[x + xd][y + yd], a[x + 2 * xd][y + yd], a[x + 2 * xd][y], a[x + xd][y]});
				swap(a[x][y], a[x + xd][y]);
				swap(a[x + xd][y], a[x + 2 * xd][y]);
				swap(a[x + 2 * xd][y], a[x + 2 * xd][y + yd]);
				swap(a[x + 2 * xd][y + yd], a[x + xd][y + yd]);
				swap(a[x + xd][y + yd], a[x][y + yd]);
				return;
			}
		}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) REP(j, 0, m)
		scanf("%d", a[i] + j);

	REP(i, 0, n) REP(j, 0, m)
	{
		int x = i * m + j + 1;
		int curu = -1, curv = -1;
		REP(u, 0, n) REP(v, 0, m)
		{
			if (a[u][v] == x)
			{
				curu = u;
				curv = v;
			}
		}
		while (curv < j) 
		{
			if (curu + 1 < n && curv + 1 < m)
			{
				step(curu, curv, 1, 1);
			}
			else r(curu, curv);
			++curv;
		}
		while (curv > j) 
		{
			if (curu + 1 < n) rstep(curu, curv - 1, 1, 1);
			else r(curu, curv - 1);
			--curv;
		}
		while (curu > i) 
		{
			if (curv + 1 < m) 
			{
				step(curu - 1, curv, 1, 1);
			}
			else c(curu - 1, curv);
			--curu;
		}
	}

	printf("%d\n", SZ(ans));
	for (auto u : ans)
	{
		printf("%d", SZ(u));
		for (auto v : u) printf(" %d", v);
		printf("\n");
	}

	debug("%d\n", sum);
	REP(i, 0, n)
	{
		REP(j, 0, m)
			debug("%d ", a[i][j]);
		debug("\n");
	}

	return 0;
}