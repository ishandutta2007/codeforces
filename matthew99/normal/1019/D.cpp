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

#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) | rand())
#else
#define LLFORMAT "ll"
#define Rand() (rand())
#endif

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

struct point
{
	int x, y;

	point() { }
	point(int _x, int _y): x(_x), y(_y) { }

	friend point operator+(const point &x, const point &y) { return point(x.x + y.x, x.y + y.y); }
	friend point &operator+=(point &x, const point &y) { x.x += y.x, x.y += y.y; return x; }
	friend point operator-(const point &x, const point &y) { return point(x.x - y.x, x.y - y.y); }
	friend point &operator-=(point &x, const point &y) { x.x -= y.x, x.y -= y.y; return x; }
	friend bool operator<(const point &x, const point &y) { if (x.x == y.x) return x.y < y.y; return x.x < y.x; }
	friend LL operator*(const point &x, const point &y) { return (LL)x.x * y.x + (LL)x.y * y.y; }
	friend LL operator^(const point &x, const point &y) { return (LL)x.x * y.y - (LL)x.y * y.x; }

}O(0, 0);


const int maxn = 2010;

int n;
LL S;
point a[maxn + 5];

LL f[maxn + 5][maxn + 5];

int pos[maxn + 5], rk[maxn + 5];

inline bool cmp(const pair<int, int> &x, const pair<int, int> &y)
{
	point u = a[x.y] - a[x.x];
	point v = a[y.y] - a[y.x];
	if ((O < u) != (O< v))
	{
		return (O < u) > (O < v);
	}
	return (u ^ v) < 0;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%" LLFORMAT "d", &n, &S), S <<= 1;
	REP(i, 0, n)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
	}
	REP(i, 0, n) REP(j, 0, n) f[i][j] = a[i] ^ a[j];
	REP(i, 0, n) pos[i] = i;
	sort(pos, pos + n, [&](int x, int y) { return a[x] < a[y]; });
	REP(i, 0, n) rk[pos[i]] = i;

	vector<pair<int, int> > all;
	REP(i, 0, n) REP(j, 0, n) if (i != j)
		all.pb(mp(i, j));
	sort(ALL(all), cmp);
	REP(i, 0, SZ(all))
	{
		int u = all[i].x, v = all[i].y;
		assert(rk[v] - rk[u] == 1);
		int l = rk[v] + 1, r = n - 1;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (f[v][u] + f[u][pos[mid]] + f[pos[mid]][v] < S) l = mid + 1;
			else r = mid;
		}
		if (f[v][u] + f[u][pos[l]] + f[pos[l]][v] == S)
		{
			puts("Yes");
			printf("%d %d\n", a[v].x, a[v].y);
			printf("%d %d\n", a[u].x, a[u].y);
			printf("%d %d\n", a[pos[l]].x, a[pos[l]].y);
			return 0;
		}
		swap(rk[u], rk[v]);
		swap(pos[rk[u]], pos[rk[v]]);
	}
	puts("No");
	return 0;
}