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

const int Mod = 1e9 + 7;

const int maxn = 1000100;

int n;
int a[maxn + 5];
int fa[maxn + 5];

LL sum[maxn + 5];

int num[maxn + 5];

int dp[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	fa[0] = -1;
	REP(i, 1, n) scanf("%d", fa + i), --fa[i];
	for (int i = n - 1; i >= 0; --i)
	{
		sum[i] += a[i];
		if (~fa[i]) sum[fa[i]] += sum[i];
	}
	vector<LL> pr;
	LL u = sum[0];
	for (LL i = 2; i * i <= u; ++i)
		if (!(u % i))
		{
			pr.pb(i);
			while (!(u % i)) u /= i;
		}
	REP(i, 0, n)
	{
		LL tmp = __gcd(sum[0], sum[i]);
		if (sum[0] / tmp <= n) ++num[sum[0] / tmp];
	}
	for (int i = n; i >= 1; --i)
		for (int j = i << 1; j <= n; j += i)
			num[j] += num[i];
	for (int i = n; i >= 1; --i)
		if (num[i] == i)
		{
			dp[i] = 1;
			for (int j = i << 1; j <= n; j += i)
				(dp[i] += dp[j]) %= Mod;
		}
	int ans = dp[1];
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}