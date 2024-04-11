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

const int Mod = 998244353;

const int maxn = 510;

inline LL test(LL a, int b)
{
	LL ret = pow(a, 1. / b) + .5;
	LL tmp = 1;
	REP(i, 0, b) tmp *= ret;
	if (tmp == a) return ret;
	return -1;
}

int n;
LL a[maxn + 5];

map<LL, int> all;

inline void go(LL x)
{
	if (all.count(x)) return;
	cerr << x << endl;
	REP(i, 0, n) 
	{
		LL u = a[i];
		while (!(u % x)) ++all[x], u /= x;
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	int ans = 1;
	REP(i, 0, n) cin >> a[i];
	REP(i, 0, n)
	{
		LL tmp = -1;
		for (int j = 4; j >= 2; --j)
			if (~(tmp = test(a[i], j)))
			{
				go(tmp);
				break;
			}
		if (!~tmp)
		{
			bool found = 0;
			REP(j, 0, n) if (a[j] != a[i] && __gcd(a[i], a[j]) > 1)
			{
				LL u = __gcd(a[i], a[j]);
				LL v = a[i] / u;
				go(u), go(v);
				found = 1;
				break;
			}
			if (!found)
			{
				REP(j, 0, i) if (a[j] == a[i]) found = 1;
				if (!found)
				{
					int cnt = 0;
					REP(j, 0, n) if (a[j] == a[i]) ++cnt;
					ans = (LL)ans * (cnt + 1) % Mod;
					ans = (LL)ans * (cnt + 1) % Mod;
				}
			}
		}
	}
	for (auto u : all) ans = (LL)ans * (u.y + 1) % Mod;
	printf("%d\n", ans);
	return 0;
}