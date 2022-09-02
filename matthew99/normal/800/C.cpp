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

int ex_gcd(const int &a, const int &b, int &x, int &y)
{
	if (!b)
	{
		x = 1, y = 0;
		return a;
	}
	int d = ex_gcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

const int maxm = 200100;

int n, m;

bool ban[maxm + 5];

int cnt[maxm + 5];
vector<int> seq[maxm + 5];

int dp[maxm + 5];
int pre[maxm + 5];

int a[maxm + 5];
int ans[maxm + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(ban, 0, sizeof ban);
	scanf("%d%d", &n, &m);
	REP(i, 0, n)
	{
		int x;
		scanf("%d", &x);
		ban[x] = 1;
	}
	REP(i, 0, m) if (!ban[i]) ++cnt[__gcd(i, m)], seq[__gcd(i, m)].pb(i);
	memset(dp, -1, sizeof dp);
	memset(pre, -1, sizeof pre);
	dp[1] = 0;
	for (int i = 1; i <= m; ++i) if (!(m % i))
	{
		dp[i] += cnt[i];
		for (int j = i << 1; j <= m; j += i) if (chkmax(dp[j], dp[i])) pre[j] = i;
	}
	int cur = dp[m];
	int u = m;
	while (~u)
	{
		for (auto x : seq[u]) a[--cur] = x;
		u = pre[u];
	}
	int now = 1;
	printf("%d\n", dp[m]);
	REP(i, 0, dp[m])
	{
		if (!i) ans[i] = a[i];
		else
		{
			ans[i] = 1;
			int d0 = __gcd(a[i - 1], m), d1 = __gcd(a[i], m);
			if (d1 != d0) ans[i] = d1 / d0;
			int x, y;
			ex_gcd(a[i - 1] / d0, m / d0, x, y);
			(x += m) %= m;
			ans[i] = (LL)ans[i] * x % m * (a[i] / d1) % m;
		}
		(ans[i] += m) %= m;
		now = (LL)now * ans[i] % m;
		assert(now == a[i]);
		printf("%d ", ans[i]);
	}
	return 0;
}