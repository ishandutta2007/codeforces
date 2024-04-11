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

const int maxn = 2010;

int n, nn = 0;
pair<LL, LL> a[maxn + 5];

bool neutralized[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	LL meanx = 0, meany = 0;
	REP(i, 0, n) scanf("%" LLFORMAT "d%" LLFORMAT "d", &a[i].x, &a[i].y), meanx += a[i].x, meany += a[i].y;
	REP(i, 0, n) a[i].x = a[i].x * n - meanx, a[i].y = a[i].y * n - meany;
	REP(i, 0, n) if (a[i].x == 0 && a[i].y == 0) neutralized[i] = 1;
	REP(i, 0, n) if (!neutralized[i])
		REP(j, 0, i) if (!neutralized[j])
			if (a[i].x == -a[j].x && a[i].y == -a[j].y)
			{
				neutralized[i] = neutralized[j] = 1;
				break;
			}
	nn = 0;
	REP(i, 0, n) if (!neutralized[i]) a[nn++] = a[i];
	n = nn;
	if (!n)
	{
		printf("-1\n");
		return 0;
	}
	assert(n != 0);
	set<pair<LL, LL> > ans;
	REP(i, 0, n)
	{
		//ax0 + by0 + ax1 + by1 = 0
		//a(x0 + x1) + b(y0 + y1) = 0
		LL u = a[0].y + a[i].y, v = -(a[0].x + a[i].x);
		LL d = __gcd(u, v);
		u /= d, v /= d;
		if (abs(u) + abs(v) > 1e8) continue;
		if (u < 0) u = -u, v = -v;
		else if (!u && v < 0) u = -u, v = -v;
		multiset<LL> all;
		REP(j, 0, n) 
		{
			LL tmp = u * a[j].x + v * a[j].y;
			if (tmp)
			{
				if (all.count(-tmp)) all.erase(all.find(-tmp));
				else all.insert(tmp);
			}
		}
		if (!SZ(all)) ans.insert(mp(u, v));
	}
	printf("%d\n", SZ(ans));
	return 0;
}