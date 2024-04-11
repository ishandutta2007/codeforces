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

inline int get(char c)
{
	if (isdigit(c)) return c - '0';
	return c - 'a' + 10;
}

inline bool check(char *s)
{
	LL ret = 0;
	int to_xor = 0;
	for (int i = 0; s[i]; ++i)
	{
		int tmp = get(s[i]);
		(ret <<= 4) |= tmp;
		to_xor |= 1 << tmp;
	}
	return (ret ^ (to_xor)) < ret;
}

const int maxn = 16, base = 16;

inline LL work(char *s)
{
	int a[maxn + 5] = {0};
	int n = strlen(s);
	REP(i, 0, n) a[i] = get(s[i]);
	static LL dp[maxn + 5][2][base + 1];
	LL ans = 0;
	REP(lim, 1, base)
	{
		memset(dp, 0, sizeof dp);
		dp[0][0][0] = 1;
		int p0 = n - (lim >> 2) - 1, p1 = lim & 3;
		if (p0 < 0) continue;
		REP(i, 0, n)
		{
			REP(j, 0, 2) 
			{
				int nxt[2][base + 1] = {0};
				REP(k, 0, lim + 1)
				{
					if (!j && k > a[i]) break;
					if (i == p0 && !((k >> p1) & 1)) continue;
					int nxtj = j | (k < a[i]);
					++nxt[nxtj][k];
				}
				REP(k, 0, 2)
				{
					LL sum = 0;
					int cnt = 0;
					REP(l, 0, lim + 1)
					{
						sum += dp[i][j][l];
						dp[i + 1][k][l] += sum * nxt[k][l];
						dp[i + 1][k][l] += dp[i][j][l] * cnt;
						cnt += nxt[k][l];
					}
				}
			}
		}
		ans += dp[n][0][lim] + dp[n][1][lim];
	}
	return ans;
}

char l[19], r[19];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s%s", l, r);
		cout << work(r) - work(l) + check(l) << endl;
	}
	return 0;
}