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

int go[26][26];

int n, qn;

int dp[7][26];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	static char a[100], b[100];
	memset(go, -1, sizeof go);
	scanf("%d%d", &n, &qn);
	REP(i, 0, qn)
	{
		scanf("%s%s", a, b);
		go[a[0] - 'a'][a[1] - 'a'] = b[0] - 'a';
	}
	REP(i, 0, 26) dp[1][i] = 1;
	REP(i, 1, n)
	{
		REP(j, 0, 26) if (dp[i][j]) REP(k, 0, 26) if (~go[j][k]) dp[i + 1][go[j][k]] += dp[i][j];
	}
	printf("%d\n", dp[n][0]);
	return 0;
}