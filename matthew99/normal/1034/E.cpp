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

#define ctz __builtin_ctz
#define bcnt __builtin_popcount

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxbit = 21;
const int maxabs = 1 << maxbit;

const LL odd = 5864062014805LL;

int n;
LL a[maxabs + 5];
LL b[maxabs + 5];
LL c[maxabs + 5];

inline LL add(const LL &x, const LL &y)
{
	return x ^ y ^ ((x & y & odd) << 1);
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	static char s[maxabs + 5];
	scanf("%s", s);
	REP(i, 0, 1 << n) a[i] = LL(s[i] - '0') << (bcnt(i) << 1);
	scanf("%s", s);
	REP(i, 0, 1 << n) b[i] = LL(s[i] - '0') << (bcnt(i) << 1);
	REP(i, 0, n) REP(j, 0, 1 << n)
		if ((j >> i & 1))
			a[j] = add(a[j], a[j ^ (1 << i)]);
	REP(i, 0, n) REP(j, 0, 1 << n)
		if ((j >> i & 1))
			b[j] = add(b[j], b[j ^ (1 << i)]);
	REP(i, 0, 1 << n)
	{
		c[i] = 0;
		REP(j, 0, n + 1) 
		{
			if (b[i] >> (j << 1) & 1) c[i] = add(c[i], a[i] << (j << 1));
			if (b[i] >> (j << 1 | 1) & 1) c[i] = add(c[i], (a[i] & odd) << (j << 1 | 1));
		}
	}
	REP(i, 0, n) REP(j, 0, 1 << n) if ((j >> i & 1))
	{
		c[j] = add(c[j], add(~c[j ^ (1 << i)], odd));
	}
	REP(i, 0, 1 << n)
	{
		printf("%d", int(c[i] >> (bcnt(i) << 1) & 3));
	}
	return 0;
}