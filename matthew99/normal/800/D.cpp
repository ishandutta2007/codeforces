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

const int maxn = 1000100;

const int maxdigit = 6;

const int maxval = 1000000;

const int pw10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

int n;
int a[maxn + 5];

int sum[maxval + 5][3];
int dp[maxval + 5];

int pw2[maxn + 5];

inline void prepare()
{
	pw2[0] = 1;
	REP(i, 0, maxn) (pw2[i + 1] = pw2[i] << 1) %= Mod;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	scanf("%d", &n);
	REP(i, 0, n) 
	{
		scanf("%d", a + i);
		int cur = 1;
		REP(j, 0, 3)
		{
			(sum[a[i]][j] += cur) %= Mod;
			cur = (LL)cur * a[i] % Mod;
		}
	}
	REP(i, 0, maxdigit)
	{
		for (int j = maxval - 1; j >= 0; --j)
			if (j / pw10[i] % 10 < 9) 
				REP(k, 0, 3) (sum[j][k] += sum[j + pw10[i]][k]) %= Mod;
	}
	REP(i, 0, maxval)
	{
		dp[i] = 0;
		if (sum[i][0] >= 1) (dp[i] += (LL)sum[i][2] * pw2[sum[i][0] - 1] % Mod) %= Mod;
		if (sum[i][0] >= 2) (dp[i] += ((LL)sum[i][1] * sum[i][1] - sum[i][2]) % Mod * pw2[sum[i][0] - 2] % Mod) %= Mod;
	}
	REP(i, 0, maxdigit)
	{
		REP(j, 0, maxval)
			if (j / pw10[i] % 10 < 9) 
				(dp[j] -= dp[j + pw10[i]]) %= Mod;
	}
	LL ans = 0;
	REP(i, 0, maxval) if (dp[i])
	{
		(dp[i] += Mod) %= Mod;
		ans ^= (LL)i * dp[i];
	}
	cout << ans << endl;
	return 0;
}