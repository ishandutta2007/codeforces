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

const int maxn = 300100;

int n;
pair<int, int> a[maxn + 5];

int ans = 0;

inline void work()
{
	sort(a, a + n);
	REP(ii, 0, 2)
	{
		reverse(a, a + n);
		int Miny = oo, Maxy = -oo;
		for (int i = n - 1; i >= 0; --i)
		{
			chkmin(Miny, a[i].y);
			chkmax(Maxy, a[i].y);
			chkmax(ans, (abs(a[n - 1].x - a[i].x) + Maxy - a[i].y) * 2);
			chkmax(ans, (abs(a[n - 1].x - a[i].x) + a[i].y - Miny) * 2);
		}
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	int Minx = oo, Maxx = -oo, Miny = oo, Maxy = -oo;
	REP(i, 0, n) scanf("%d%d", &a[i].x, &a[i].y), chkmin(Minx, a[i].x), chkmax(Maxx, a[i].x), chkmin(Miny, a[i].y), chkmax(Maxy, a[i].y);

	work();
	REP(i, 0, n) swap(a[i].x, a[i].y);
	work();

	printf("%d ", ans);
	REP(i, 4, n + 1) printf("%d\n", (Maxy - Miny + Maxx - Minx) * 2);
	return 0;
}