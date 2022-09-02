#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
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

const int maxn = 100100;

struct frac
{
	int x, y;

	frac() { }
	frac(int _x, int _y): x(_x), y(_y) { if (y < 0) x = -x, y = -y; }

	friend bool operator < (const frac &x, const frac &y)
	{
		return (LL)x.x * y.y < (LL)x.y * y.x;
	}

	friend bool operator > (const frac &x, const frac &y)
	{
		return (LL)x.x * y.y > (LL)x.y * y.x;
	}



};

int n;

int xl, yl, xr, yr;
frac Min, Max;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	scanf("%d%d%d%d", &xl, &yl, &xr, &yr);
	Min = frac(0, 1), Max = frac(oo, 1);
	REP(i, 0, n)
	{
		int ux, uy, vx, vy;
		scanf("%d%d%d%d", &ux, &uy, &vx, &vy);
		if (!vx)
		{
			if (ux <= xl || ux >= xr) EXIT("-1");
		}
		else
		{
			frac tmp0 = frac(xl - ux, vx), tmp1 = frac(xr - ux, vx);
			if (tmp0 > tmp1) swap(tmp0, tmp1);
			chkmax(Min, tmp0);
			chkmin(Max, tmp1);
		}
		if (!vy)
		{
			if (uy <= yl || uy >= yr) EXIT("-1");
		}
		else
		{
			frac tmp0 = frac(yl - uy, vy), tmp1 = frac(yr - uy, vy);
			if (tmp0 > tmp1) swap(tmp0, tmp1);
			chkmax(Min, tmp0);
			chkmin(Max, tmp1);
		}
	}
	if (Min < Max) printf("%.15f\n", (double)Min.x / Min.y);
	else printf("-1\n");
	return 0;
}