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

#define ctz __builtin_ctz
#define bcnt __builtin_popcount

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 20, maxlen = 1 << maxn, maxm = 100000;

inline void fwt(LL *a, int n)
{
	for (int i = 2; i <= n; i <<= 1)
		for (int j = 0; j < n; j += i)
		{
			LL *l = a + j, *r = a + j + (i >> 1);
			REP(k, 0, i >> 1) *l += *r, *r = *l - LL(*r << 1), ++l, ++r;
		}
}

LL num[maxlen + 5], cnt[maxlen + 5];

int n, m;

int grid[maxm + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	static char s[maxm + 5];
	REP(i, 0, n)
	{
		scanf("%s", s);
		REP(j, 0, m) if (s[j] == '1') grid[j] |= 1 << i;
	}
	REP(i, 0, m) ++cnt[grid[i]];
	REP(i, 0, 1 << n) num[i] = min(bcnt(i), n - bcnt(i));
	fwt(num, 1 << n), fwt(cnt, 1 << n);
	REP(i, 0, 1 << n) num[i] *= cnt[i];
	fwt(num, 1 << n);
	LL ans = LLONG_MAX;
	REP(i, 0, 1 << n) chkmin(ans, num[i]);
	ans >>= n;
	printf("%I64d\n", ans);
	return 0;
}