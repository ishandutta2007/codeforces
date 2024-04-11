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

const int maxn = 80;

int n;
char s[maxn + 5];

vector<int> V, K, others;
int dp[maxn + 5][maxn + 5][maxn + 5][2];

int pre_cnt[maxn + 5][3];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	scanf("%s", s);
	REP(i, 0, n)
	{
		pre_cnt[i][0] = SZ(V);
		pre_cnt[i][1] = SZ(K);
		pre_cnt[i][2] = SZ(others);
		if (s[i] == 'V') V.pb(i);
		else if (s[i] == 'K') K.pb(i);
		else others.pb(i);
	}
	memset(dp, oo, sizeof dp);
	dp[0][0][0][0] = 0;
	REP(i, 0, SZ(V) + 1) REP(j, 0, SZ(K) + 1) REP(k, 0, SZ(others) + 1) REP(isv, 0, 2) if (dp[i][j][k][isv] < oo)
	{
		if (i < SZ(V))
		{
			chkmin(dp[i + 1][j][k][1], dp[i][j][k][isv] + abs(i + j + k - max(pre_cnt[V[i]][0], i) - max(pre_cnt[V[i]][1], j) - max(pre_cnt[V[i]][2], k))); 
		}
		if (!isv && j < SZ(K))
		{
			chkmin(dp[i][j + 1][k][0], dp[i][j][k][isv] + abs(i + j + k - max(pre_cnt[K[j]][0], i) - max(pre_cnt[K[j]][1], j) - max(pre_cnt[K[j]][2], k))); 
		}
		if (k < SZ(others))
		{
			chkmin(dp[i][j][k + 1][0], dp[i][j][k][isv] + abs(i + j + k - max(pre_cnt[others[k]][0], i) - max(pre_cnt[others[k]][1], j) - max(pre_cnt[others[k]][2], k))); 
		}
	}
	printf("%d\n", min(dp[SZ(V)][SZ(K)][SZ(others)][0], dp[SZ(V)][SZ(K)][SZ(others)][1]));
	return 0;
}