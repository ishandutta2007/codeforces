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

struct point
{
	int x, y;

	point() { }
	point(const int &_x, const int &_y): x(_x), y(_y) { }

	friend point operator+(const point &x, const point &y) { return point(x.x + y.x, x.y + y.y); }
	friend point &operator+=(point &x, const point &y) { x.x += y.x, x.y += y.y; return x; }
	friend point operator-(const point &x, const point &y) { return point(x.x - y.x, x.y - y.y); }
	friend point &operator-=(point &x, const point &y) { x.x -= y.x, x.y -= y.y; return x; }
	friend point operator*(const point &x, const double &y) { return point(x.x * y, x.y * y); }
	friend point operator/(const point &x, const double &y) { return point(x.x / y, x.y / y); }
	friend bool operator<(const point &x, const point &y) { if (x.x == y.x) return x.y < y.y; return x.x < y.x; }
	friend LL operator*(const point &x, const point &y) { return (LL)x.x * y.x + (LL)x.y * y.y; }
	friend LL operator^(const point &x, const point &y) { return (LL)x.x * y.y - (LL)x.y * y.x; }

} O(0, 0);

const int maxn = 2010;

int n;
point a[maxn + 5];

int id;

inline bool cmp(int x, int y)
{
	point u = a[x] - a[id];
	point v = a[y] - a[id];
	if ((O < u) != (O < v)) return (O < u) < (O < v);
	return (u ^ v) > 0;
}

int cnt[maxn + 5][maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d%d", &a[i].x, &a[i].y);
	REP(i, 0, n)
	{
		static int pos[(maxn << 1) + 5];
		REP(j, 0, n) pos[j] = j;
		swap(pos[i], pos[n - 1]);
		id = i;
		sort(pos, pos + n - 1, cmp);
		REP(j, 0, n - 1) pos[j + n - 1] = pos[j];
		int pt = 0;
		REP(j, n - 1, (n - 1) << 1)
		{
			while (j - pt >= n - 1 || (((a[pos[j]] - a[i]) ^ (a[pos[pt]] - a[i])) > 0)) ++pt;
			cnt[i][pos[j]] = j - pt;
		}
	}
	LL ans = 0;
	REP(i, 0, n) REP(j, 0, i)
	{
		ans += (LL)cnt[i][j] * (cnt[i][j] - 1) * cnt[j][i] * (cnt[j][i] - 1) >> 2;
	}
	cout << ans << endl;
	return 0;
}