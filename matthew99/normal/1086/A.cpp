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

const int maxn = 100100;

int n;
int s;

int d[maxn + 5];

set<pair<int, int> > ans;

inline void go_from(int xa, int ya, int xb, int yb, int ty)
{
	if (ty == 0)
	{
		REP(i, xa, xb) ans.insert(mp(i, ya));
		for (int i = ya; i <= yb; ++i) ans.insert(mp(xb, i));
		for (int i = ya; i >= yb; --i) ans.insert(mp(xb, i));
	}
	else
	{
		for (int i = ya; i < yb; ++i) ans.insert(mp(xa, i));
		for (int i = ya; i > yb; --i) ans.insert(mp(xa, i));
		REP(i, xa, xb + 1) ans.insert(mp(i, yb));
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	pair<int, int> a[3];
	REP(i, 0, 3) scanf("%d%d", &a[i].x, &a[i].y);
	sort(a, a + 3);
	go_from(a[0].x, a[0].y, a[1].x, a[1].y, 0);
	go_from(a[1].x, a[1].y, a[2].x, a[2].y, 1);
	printf("%d\n", SZ(ans));
	for (auto u : ans) printf("%d %d\n", u.x, u.y);
	return 0;
}