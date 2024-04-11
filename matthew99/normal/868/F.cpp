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

const int maxn = 100100, maxk = 20;

int n, K;
int a[maxn + 5];

LL dp[maxk + 5][maxn + 5];

int nowl, nowr;
LL cost;

int cnt[maxn + 5];

inline void add(int x)
{
	cost += cnt[a[x]]++;
}

inline void del(int x)
{
	cost -= --cnt[a[x]];
}

inline void move(int l, int r)
{
	while (nowl > l) add(--nowl);
	while (nowr < r) add(nowr++);
	while (nowl < l) del(nowl++);
	while (nowr > r) del(--nowr);
}

inline void work(int step, int l0, int r0, int l1, int r1)
{
	if (l0 == r0) return;
	int mid0 = (l0 + r0) >> 1;
	int mid1 = -1;
	LL tmp = LLONG_MAX;
	REP(i, l1, min(r1, mid0))
	{
		move(i, mid0);
		if (chkmin(tmp, dp[step][i] + cost)) mid1 = i;
	}
	chkmin(dp[step + 1][mid0], tmp);
	work(step, l0, mid0, l1, mid1 + 1);
	work(step, mid0 + 1, r0, mid1, r1);
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	REP(i, 0, n) scanf("%d", a + i);
	memset(dp, oo, sizeof dp);
	dp[0][0] = 0;
	REP(i, 0, K)
	{
		work(i, 0, n + 1, 0, n);
	}
	cout << dp[K][n] << endl;
	return 0;
}