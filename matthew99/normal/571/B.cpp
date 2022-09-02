#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int oo = 0x3f3f3f3f;

template<typename T> T &Read(T &x)
{
	static char c;
	while (!isdigit(c = getchar()));
	x = c - '0';
	while (isdigit(c = getchar())) (x *= 10) += c - '0';
	return x;
}

const int maxn = 300000, maxk = 5000;

int n;
int a[maxn + 5];

LL dp[2][maxk + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int k;
	scanf("%d%d", &n, &k);
	REP(i, 0, n) scanf("%d", a + i);
	sort(a, a + n);
	int num0 = (n + k - 1) / k;
	int num = num0 * k - n;
	dp[0][0] = 0;
	REP(i, 0, k)
	{
		int cur = i & 1, nxt = cur ^ 1;
		memset(dp[nxt], oo, sizeof dp[nxt]);
		REP(j, 0, min(i, num) + 1)
		{
			if (dp[cur][j] >= 0x3f3f3f3f3f3f3f3fLL) continue;
			assert(dp[cur][j] >= 0);
			int p = i * num0 - j;
			if (p + num0 - 1 < n) chkmin(dp[nxt][j], dp[cur][j] + a[p + num0 - 1] - a[p]);
			if (j + 1 <= num)
			{
				if (p + num0 - 2 < n) chkmin(dp[nxt][j + 1], dp[cur][j] + a[p + num0 - 2] - a[p]);
			}
		}
	}
	printf("%I64d\n", dp[k & 1][num]);
	return 0;
}