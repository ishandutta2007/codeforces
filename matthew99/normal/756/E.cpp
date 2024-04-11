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

const int Mod = 1e9 + 7;

const int maxn = 300100, maxb = 300100, maxm = 10000;

const int P = 1e4;
const int pw[] = {1, 10, 100, 1000};

int n;
int a[maxn + 5];
int b[maxn + 5];
int dpn;
int dp[maxb + 5];

char s[maxm + 5];
int mn = 0;
int m[maxm + 5];

int ans;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n - 1) scanf("%d", a + i);
	REP(i, 0, n) scanf("%d", b + i);
	scanf("%s", s);
	int sn = strlen(s);
	reverse(s, s + sn);
	mn = ((sn - 1) >> 2) + 1;
	REP(i, 0, sn) m[i >> 2] += (s[i] - '0') * pw[i & 3];
	memset(dp, 0, sizeof dp);
	dpn = 1;
	dp[0] = 1;
	REP(i, 0, n)
	{
		static int nxt[maxb + 5];
		int sum = 0;
		REP(j, 0, dpn + b[i])
		{
			if (j < dpn) (sum += dp[j]) %= Mod;
			if (j > b[i]) (sum -= dp[j - b[i] - 1]) %= Mod;
			nxt[j] = sum;
		}
		dpn += b[i];
		memcpy(dp, nxt, sizeof(dp[0]) * dpn);
		if (i < n - 1 && a[i] > 1)
		{
			int res = 0;
			for (int j = mn - 1; j >= 0; --j)
			{
				LL tmp = m[j] + (LL)res * P;
				res = tmp % a[i];
				m[j] = tmp / a[i];
			}
			while (mn && !m[mn - 1]) --mn;
			REP(j, 0, dpn) if (j % a[i] == res) dp[j / a[i]] = dp[j];
			dpn = (dpn - res + a[i] - 1) / a[i];
		}
	}
	if (mn > 2) ans = 0;
	else
	{
		int tmp = 0;
		for (int i = mn - 1; i >= 0; --i) (tmp *= P) += m[i];
		if (tmp >= dpn) ans = 0;
		else ans = dp[tmp];
	}
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}