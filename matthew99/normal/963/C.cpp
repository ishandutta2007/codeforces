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

const int maxn = 200100;

int n;
pair<pair<LL, LL>, LL> a[maxn + 5];
map<LL, map<LL, LL> > cnt;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n)
	{
		scanf("%" LLFORMAT "d%" LLFORMAT "d%" LLFORMAT "d", &a[i].x.x, &a[i].x.y, &a[i].y);
		cnt[a[i].x.x][a[i].x.y] += a[i].y;
	}
	map<LL, LL> lst;
	LL t = 0;
	bool fir = 1;
	for (auto &u : cnt)
	{
		LL tmp = 0;
		for (auto v : u.y)
		{
			tmp = __gcd(tmp, v.y);
		}
		for (auto &v : u.y)
		{
			v.y /= tmp;
		}
		if (!fir && u.y != lst)
		{
			printf("0\n");
			return 0;
		}
		lst = u.y;
		fir = 0;
		t = __gcd(t, tmp);
	}
	LL ans = 1;
	for (LL i = 2; i * i <= t; ++i)
	{
		int pw = 0;
		while (!(t % i)) t /= i, ++pw;
		ans *= pw + 1;
	}
	if (t > 1) ans *= 2;
	printf("%" LLFORMAT "d\n", ans);
	return 0;
}