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

const int maxn = 4000;

int p, r;

char A[maxn + 5];

int n;
LL a[maxn + 5];

inline int work(char *s, LL *ret)
{
	static LL tmp[maxn + 5];
	int l = strlen(s);
	reverse(s, s + l);
	REP(i, 0, l) tmp[i] = s[i] - '0';
	int cnt = 0;
	while (l)
	{
		bool flag = 0;
		for (int j = l - 1; j >= 0; --j)
		{
			(j ? tmp[j - 1] : ret[cnt]) += tmp[j] % p * 10;
			tmp[j] /= p;
			if (tmp[j]) flag = 1;
			if (!flag) l = j;
		}
		ret[cnt] /= 10;
		++cnt;
	}
	return cnt;
}

int dp[maxn + 5][maxn + 5][2][2];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &p, &r);
	scanf("%s", A);
	n = work(A, a);
	reverse(a, a + n);
	dp[0][0][0][1] = 1;
	REP(i, 0, n)
		REP(j, 0, i + 1)
			REP(k, 0, 2)
				REP(k0, 0, 2)
				{
					if (dp[i][j][k][k0])
					{
						REP(l, 0, 2)
						{
							REP(l0, 0, k0 + 1)
							{
								int cnt = 0, sum = 0, u = -1;
								if (k0) 
								{
									if (!l0) cnt = a[i], sum = ((LL)a[i] * (a[i] - 1) >> 1) % Mod;
									else cnt = 1, sum = a[i];
								}
								else cnt = p, sum = ((LL)p * (p - 1) >> 1) % Mod;
								if (k) u = ((LL)cnt * (p - (!l)) - sum) % Mod;
								else u = (sum + (!l) * cnt) % Mod;
								(dp[i + 1][j + l][l][l0] += (LL)u * dp[i][j][k][k0] % Mod) %= Mod;
							}
						}
					}
				}
	if (r >= n) printf("0\n"); 
	else
	{
		int ret = 0;
		REP(i, r, n) (ret += dp[n][i][0][0]) %= Mod, (ret += dp[n][i][0][1]) %= Mod;
		(ret += Mod) %= Mod;
		printf("%d\n", ret);
	}
	return 0;
}