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

const int maxn = 500, maxk = 500;

bitset<maxk + 5> dp[maxn + 5][maxk + 5];

int n, K;
int a[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	REP(i, 0, n) scanf("%d", a + i);
	dp[0][0][0] = 1;
	REP(i, 0, n) REP(j, 0, K + 1)
	{
		dp[i + 1][j] |= dp[i][j];
		if (j + a[i] <= K) dp[i + 1][j + a[i]] |= dp[i][j];
		dp[i + 1][j] |= dp[i][j] << a[i];
	}
	vector<int> ans;
	REP(i, 0, K + 1) if (dp[n][i][K - i]) ans.pb(i);
	printf("%d\n", SZ(ans));
	for (auto u : ans) printf("%d ", u);
	return 0;
}