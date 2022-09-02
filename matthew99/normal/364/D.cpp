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
#define Rand() ((rand() << 15) | rand())

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 1000000;

const int __buffsize = 100000;
char __buff[__buffsize];
char *__buffs, *__buffe;

#define getc() (__buffs == __buffe ? fread(__buff, 1, __buffsize, stdin), __buffe = __buff + __buffsize, *((__buffs = __buff)++) : *(__buffs++))

template<typename T> inline T &Read(T &x)
{
	static char c;
	while (1) 
	{ 
		c = getc(); 
		if (c == '-' || (c >= '0' && c <= '9')) break; 
	}
	bool flag = c == '-';
	x = flag ? 0 : c - '0';
	while (1)
	{
		c = getc();
		if (c < '0' || c > '9') break;
		(x *= 10) += c - '0';
	}
	if (flag) x = -x;
	return x;
}

#undef getc

const int max0 = 1000000;

int n;
LL a[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	srand(time(NULL));
#endif
	Read(n);
	REP(i, 0, n) Read(a[i]);
	LL ans = 1;
	while (clock() <= 3.0 * CLOCKS_PER_SEC)
	{
		int t = Rand() % n;
		vector<LL> all;
		for (int i = 1; (LL)i * i <= a[t]; ++i)
		{
			if (!(a[t] % i)) 
			{
				all.pb(i);
				if ((LL)i * i != a[t]) all.pb(a[t] / i);
			}
		}
		sort(ALL(all));
		int m = SZ(all);
		static int cnt[max0 + 5];
		memset(cnt, 0, sizeof cnt);
		REP(i, 0, n) ++cnt[lower_bound(ALL(all), __gcd(a[t], a[i])) - all.begin()];
		REP(i, 0, m) REP(j, 0, i) if (!(all[i] % all[j])) cnt[j] += cnt[i];
		REP(i, 0, m) if ((cnt[i] << 1) >= n) chkmax(ans, all[i]);
	}
	printf("%I64d\n", ans);
	return 0;
}