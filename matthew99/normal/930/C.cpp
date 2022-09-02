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

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 100100;

int n, m;
int sum[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n)
	{
		int l, r;
		scanf("%d%d", &l, &r), --l;
		++sum[l];
		--sum[r];
	}
	REP(i, 0, m) sum[i + 1] += sum[i];

	static int dp[maxn + 5];
	static int fen[maxn + 5];
	memset(fen, 0, sizeof fen);
	memset(dp, 0, sizeof dp);
	REP(i, 0, m)
	{
		dp[i] = 0;
		for (int j = sum[i] + 1; j > 0; j -= j & -j)
			chkmax(dp[i], fen[j]);
		++dp[i];
		for (int j = sum[i] + 1; j <= n; j += j & -j)
			chkmax(fen[j], dp[i]);
	}

	memset(fen, 0, sizeof fen);
	int ans = 0;
	for (int i = m - 1; i >= 0; --i)
	{
		int tmp = 0;
		for (int j = sum[i] + 1; j > 0; j -= j & -j)
			chkmax(tmp, fen[j]);
		chkmax(ans, dp[i] + tmp);
		++tmp;
		for (int j = sum[i] + 1; j <= n; j += j & -j)
			chkmax(fen[j], tmp);
	}

	printf("%d\n", ans);
	return 0;
}