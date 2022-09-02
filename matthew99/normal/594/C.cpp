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

const int Mod = 1e9 + 7;

const int maxn = 100000;

int n;
pair<int, int> a[maxn + 5];

int pos0[maxn + 5], pos1[maxn + 5], pos2[maxn + 5], pos3[maxn + 5];

inline bool cmp0(int x, int y)
{
	return a[x].x < a[y].x;
}

inline bool cmp1(int x, int y)
{
	return a[x].x > a[y].x;
}

inline bool cmp2(int x, int y)
{
	return a[x].y < a[y].y;
}

inline bool cmp3(int x, int y)
{
	return a[x].y > a[y].y;
}

int lst[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int k;
	scanf("%d%d", &n, &k);
	REP(i, 0, n)
	{
		int x0, y0, x1, y1;
		scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
		a[i] = mp(x0 + x1, y0 + y1);
		pos0[i] = pos1[i] = pos2[i] = pos3[i] = i;
	}
	sort(pos0, pos0 + n, cmp0);
	sort(pos1, pos1 + n, cmp1);
	sort(pos2, pos2 + n, cmp2);
	sort(pos3, pos3 + n, cmp3);
	int now = 0;
	LL ans = LLONG_MAX;
	REP(a, 0, k + 1) REP(b, 0, k + 1) REP(c, 0, k + 1) REP(d, 0, k + 1)
	{
		++now;
		int cnt = 0;
		REP(i, 0, a) if (lst[pos0[i]] != now) lst[pos0[i]] = now, ++cnt;
		REP(i, 0, b) if (lst[pos1[i]] != now) lst[pos1[i]] = now, ++cnt;
		REP(i, 0, c) if (lst[pos2[i]] != now) lst[pos2[i]] = now, ++cnt;
		REP(i, 0, d) if (lst[pos3[i]] != now) lst[pos3[i]] = now, ++cnt;
		if (cnt != k) continue;
		int Maxx = INT_MIN, Minx = INT_MAX, Maxy = INT_MIN, Miny = INT_MAX;
		REP(i, 0, n) if (lst[i] != now)
		{
			chkmax(Maxx, ::a[i].x);
			chkmin(Minx, ::a[i].x);
			chkmax(Maxy, ::a[i].y);
			chkmin(Miny, ::a[i].y);
		}
		LL xx = (LL)Maxx - Minx, yy = (LL)Maxy - Miny;
		xx = max(xx, 2LL);
		yy = max(yy, 2LL);
		if (xx & 1) ++xx;
		if (yy & 1) ++yy;
		chkmin(ans, xx * yy);
	}
	ans >>= 2;
	cout << ans << endl;
	return 0;
}