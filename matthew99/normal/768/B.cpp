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

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

inline LL up(const LL &x)
{
	if (!x) return 0;
	return (1LL << (64 - __builtin_clzll(x))) - 1;
}

inline LL cnt(const LL &n, const LL &lim)
{
	if (!lim) return 0;
	LL half = n >> 1;
	LL le = up(half);
	if (lim <= le) return cnt(half, lim);
	return half + (n & 1) + cnt(half, lim - le - 1);
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	LL n, l, r;
	cin >> n >> l >> r;
	cout << cnt(n, r) - cnt(n, l - 1) << endl;
	return 0;
}