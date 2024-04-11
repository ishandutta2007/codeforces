#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i < y; i ++)
#define rrep(i, x, y) for(int i = x - 1; i >= y; i --)
#define ll long long
#define ull unsignto long long
#define db double
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define sz(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define vi Vtor<int>
#define EPS 1e-8
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 60;
char s1[N], s2[N], a[N], b[N], c[N];
bool dp1[N][N][N], dp2[N][N][N];
int n, dp[N][N], len1, len2;
int main()
{
	scanf("%s%s%d", s1, s2, &n);
	rep(i, 0, n) scanf(" %c%*c%*c%c%c", a + i, b + i, c + i);
	len1 = strlen(s1);
	len2 = strlen(s2);
	rrep(i, len1, 0)
		rep(j, i, len1)
			rep(k, 0, 26)
				if (i == j) dp1[i][j][k] = (s1[i] - 'a' == k);
				else rep(l, 0, n)
					if (k == a[l] - 'a')
						rep(l2, i, j) dp1[i][j][k] |= dp1[i][l2][b[l] - 'a'] & dp1[l2 + 1][j][c[l] - 'a'];
	rrep(i, len2, 0)
		rep(j, i, len2)
			rep(k, 0, 26)
				if (i == j) dp2[i][j][k] = (s2[i] - 'a' == k);
				else rep(l, 0, n)
					if (k == a[l] - 'a')
						rep(l2, i, j) dp2[i][j][k] |= dp2[i][l2][b[l] - 'a'] & dp2[l2 + 1][j][c[l] - 'a'];
	memset(dp, 0x3f, sizeof(dp)); dp[0][0] = 0;
	rep(i, 1, len1 + 1)
		rep(j, 1, len2 + 1)
			rep(i1, 0, i)
				rep(j1, 0, j)
					rep(k, 0, 26)
						if (dp1[i1][i - 1][k] && dp2[j1][j - 1][k])
							dp[i][j] = min(dp[i][j], dp[i1][j1] + 1);
	printf("%d\n", dp[len1][len2] <= 100 ? dp[len1][len2] : -1);
}