#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define x first
#define y second
#define mp make_pair
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> P;
typedef long long LL;
typedef double db;
const int N = 100 + 10;
const LL inf = 1e18;
int n, a[N], b[N];
LL dp[N][N][N][2];
int sum[N][2];
char s[N];

LL DP(int l, int r, int c, int o) {
	if(sum[r][o] - sum[l - 1][o] < c) return -inf; 
	if(l > r) return 0;
	if(dp[l][r][c][o] != -1) return dp[l][r][c][o];
	LL &res = dp[l][r][c][o];
	res = 0;
	if(c == 0) {
		rep(i, 1, r - l + 1) {
			ckmax(res, DP(l + 1, r, i - 1, b[l]) - a[i - 1] + a[i]);
		}
		return res;
	}
	rep(i, l, r) {
		if(b[i] == o) {
			ckmax(res, DP(l, i - 1, 0, 0) + DP(i + 1, r, c - 1, o) - a[c - 1] + a[c]);
		}
	}
	return res;
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) rep(j, i, n) rep(k, 0, n) rep(l, 0, 1) dp[i][j][k][l] = -1;
	scanf("%s", s + 1);
	rep(i, 1, n) scanf("%d", &a[i]), b[i] = s[i] - '0';
	rep(i, 1, n) {
		rep(j, 0, 1) sum[i][j] = sum[i - 1][j];
		sum[i][b[i]]++;
	}
	printf("%lld\n", DP(1, n, 0, 0));
	return 0;
}