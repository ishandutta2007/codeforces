#include<bits/stdc++.h>

using namespace std;
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
#define mp make_pair
#define pb push_back
template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> par;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 500 + 10;
int n, k;
int a[N], b[N];
int dp[N][N];

int solve(int a[], int b[], LL A) {
	memset(dp, 0, sizeof(dp)); 
	dp[0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < k; j++) {
			if(!dp[i][j]) continue;
			dp[i + 1][j] |= dp[i][j];
			for(int d = k - min(b[i + 1], k - 1); d <= min(a[i + 1], k - 1); d++) {
				dp[i + 1][(j + d) % k] |= dp[i][j];
			}
		}
	}
	return dp[n][A % k];
}

int main() {
	scanf("%d%d", &n, &k);
	LL A = 0, B = 0;
	for(int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]), A += a[i], B += b[i];
	LL ans = (A % k + B % k);
	if(solve(a, b, A)) ans = min(ans, (A + B) % k);
	if(solve(b, a, B)) ans = min(ans, (A + B) % k);
	printf("%lld\n", (A + B - ans) / k);
	return 0;
}