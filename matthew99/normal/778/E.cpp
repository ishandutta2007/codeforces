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

const int maxn = 1010, maxm = 1010;

int an;
int n;
int a[maxm + 5];
int b[maxn + 5][maxm + 5];
int len[maxn + 5];

int dp[maxm + 5][maxn + 5];

int cost[10];

int pos[maxn + 5], ppos[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	static char s[maxm + 5];
	scanf("%s", s);
	an = strlen(s);
	reverse(s, s + an);
	REP(i, 0, an) 
	{
		if (s[i] == '?') a[i] = -1;
		else a[i] = s[i] - '0';
	}
	scanf("%d", &n);
	REP(i, 0, n)
	{
		scanf("%s", s);
		len[i] = strlen(s);
		reverse(s, s + len[i]);
		REP(j, 0, len[i]) b[i][j] = s[j] - '0';
	}
	REP(i, 0, 10) scanf("%d", cost + i);
	REP(i, 0, n) pos[i] = i;
	memset(dp, -oo, sizeof dp);
	dp[0][0] = 0;
	REP(i, 0, maxm)
	{
		static int dcnt[11];
		memset(dcnt, 0, sizeof dcnt);
		REP(j, 0, n) if (i < an || i < len[j]) ++dcnt[b[j][i]];
		REP(j, 0, n + 1)
		{
			if (dp[i][j] >= 0)
			{
				REP(k, 0, 10)
				{
					if (i >= an && k) continue;
					if (i == an - 1 && !k) continue;
					if (i < an && ~a[i] && k != a[i]) continue;
					int delta = 0;
					int carry = 0;
					REP(l, 0, 11) if (dcnt[l]) delta += dcnt[l] * cost[(l + k) % 10], carry += (l + k >= 10) * dcnt[l]; 
					chkmax(dp[i + 1][carry], dp[i][j] + delta);
				}
			}
			if (j < n) 
			{
				if (i < an || i < len[pos[j]]) --dcnt[b[pos[j]][i]];
				++dcnt[b[pos[j]][i] + 1];
			}
		}
		static int sum[10];
		memset(sum, 0, sizeof sum);
		REP(j, 0, n) ++sum[b[j][i]];
		for (int j = 9; j >= 1; --j) sum[j - 1] += sum[j];
		for (int j = n - 1; j >= 0; --j) ppos[--sum[b[pos[j]][i]]] = pos[j];
		memcpy(pos, ppos, sizeof pos);
	}
	printf("%d\n", dp[maxm][0]);
	return 0;
}