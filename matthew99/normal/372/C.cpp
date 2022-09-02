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

const int maxn = 150000, maxm = 300;

int n, m, d;
LL dp[maxn + 5];

int a[maxm + 5], b[maxm + 5], t[maxm + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &d);
	REP(i, 0, m) scanf("%d%d%d", a + i, b + i, t + i), --a[i];
	REP(i, 0, n) dp[i] = 0;
	REP(i, 0, m)
	{
		REP(j, 0, n) dp[j] += b[i] - abs(a[i] - j);
		static int q[maxn + 5];
		int head = 0, rear = 0;
		LL delta = (i == m - 1 ? 0LL : LL(t[i + 1] - t[i]) * d);
		static LL tmp[maxn + 5];
		REP(j, 0, n) tmp[j] = LLONG_MIN;
		REP(j, 0, n)
		{
			while (head != rear && q[head] < j - delta) ++head;
			while (head != rear && dp[q[rear - 1]] < dp[j]) --rear;
			q[rear++] = j;
			chkmax(tmp[j], dp[q[head]]);
		}
		head = rear = 0;
		for (int j = n - 1; j >= 0; --j)
		{
			while (head != rear && q[head] > j + delta) ++head;
			while (head != rear && dp[q[rear - 1]] < dp[j]) --rear;
			q[rear++] = j;
			chkmax(tmp[j], dp[q[head]]);
		}
		REP(j, 0, n) chkmax(dp[j], tmp[j]);
	}
	LL ans = *max_element(dp, dp + n);
	printf("%I64d\n", ans);
	return 0;
}