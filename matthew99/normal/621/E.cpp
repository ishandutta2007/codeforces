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

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int Mod = 1e9 + 7;

const int max0 = 100;

int N;

inline void mul(int a[max0 + 5][max0 + 5], int b[max0 + 5][max0 + 5])
{
	static int ans[max0 + 5][max0 + 5];
	memset(ans, 0, sizeof ans);
	REP(i, 0, N) REP(j, 0, N) REP(k, 0, N)
		(ans[i][k] += (LL)a[i][j] * b[j][k] % Mod) %= Mod;
	REP(i, 0, N) REP(j, 0, N) a[i][j] = ans[i][j];
}

int F[max0 + 5][max0 + 5];

int n, b, k, x;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d%d", &n, &b, &k, &x);
	memset(F, 0, sizeof F);
	REP(i, 0, n)
	{
		int a;
		scanf("%d", &a);
		REP(j, 0, x) ++F[j][(j * 10 + a) % x];
	}
	N = x;
	static int tmp[max0 + 5][max0 + 5];
	REP(j, 0, x) tmp[j][j] = 1;
	for ( ; b; b >>= 1, mul(F, F))
		if (b & 1) mul(tmp, F);
	printf("%d\n", tmp[0][k]);
	return 0;
}