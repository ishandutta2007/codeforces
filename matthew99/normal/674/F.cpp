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

#define ctz(x) __builtin_ctz(x)

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxp = 130;

inline int fp(int b, int e)
{
	int t = 1;
	for ( ; e; e >>= 1, b *= b)
		if (e & 1) t *= b;
	return t;
}

inline int inv(int x) { return fp(x, INT_MAX); }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	static int coe[maxp + 5];
	int n, p, qn;
	scanf("%d%d%d", &n, &p, &qn);
	chkmin(p, n - 1);
	int val = 1;
	int pw = 0;
	REP(i, 0, p + 1)
	{
		coe[i] = val << pw;
		int u = ctz(n - i), v = ctz(i + 1);
		val *= (n - i) >> u;
		pw += u;
		val *= inv((i + 1) >> v);
		pw -= v;
	}
	int ans = 0;
	REP(i, 1, qn + 1)
	{
		int tmp = 0;
		for (int j = p; j >= 0; --j) (tmp *= i) += coe[j];
		ans ^= i * tmp;
	}
	printf("%u\n", ans);
	return 0;
}