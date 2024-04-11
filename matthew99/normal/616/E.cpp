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

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int Mod = 1e9 + 7;

LL n, m;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%I64d%I64d", &n, &m);
	LL ans = 0;
	for (LL i = 1, nxt; i <= m; i = nxt)
	{
		LL tmp = n / i;
		nxt = (!tmp ? m : min(m, n / tmp)) + 1;
		(ans += ((nxt - i) % Mod) * (n % Mod)) %= Mod;
		(ans -= ((tmp % Mod) * (nxt - i) % Mod) % Mod * ((i + nxt - 1) % Mod) % Mod * ((Mod + 1) >> 1)) %= Mod;
	}
	(ans += Mod) %= Mod;
	printf("%I64d\n", ans);
	return 0;
}