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

const int maxn = 100100;

int n;
int a[maxn + 5];
int pos[maxn + 5];

int dp[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i), pos[a[i]] = i;
	memset(dp, -1, sizeof dp);
	for (int i = n; i >= 1; --i)
	{
		dp[pos[i]] = 0;
		for (int j = i; j < n; j += i)
		{
			REP(k, 0, 2)
			{
				int nxt = k ? pos[i] + j : pos[i] - j;
				if (nxt >= 0 && nxt < n && a[nxt] > i)
				{
					if (!dp[nxt])
					{
						dp[pos[i]] = 1;
					}
				}
			}
		}
	}
	REP(i, 0, n) if (dp[i]) putchar('A'); else putchar('B');
	return 0;
}