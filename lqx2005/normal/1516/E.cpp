#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
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
const int N = 400 + 10, P = 1e9 + 7;
int n, k;
int dp[N][N], inv[N], fac[N], ifac[N], und[N];

void init(int m) {
	inv[1] = 1;
	for(int i = 2; i <= m; i++) inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
	fac[0] = ifac[0] = 1;
	for(int i = 1; i <= m; i++) fac[i] = 1ll * fac[i - 1] * i % P;
	for(int i = 1; i <= m; i++) ifac[i] = 1ll * ifac[i - 1] * inv[i] % P;
	und[0] = 1;
	for(int i = 1; i <= m; i++) und[i] = 1ll * und[i - 1] * (n - i + 1) % P;
	return;
}

void initDP() {
	dp[0][0] = 1;
	for(int i = 1; i <= k; i++) {
		for(int j = 1; j <= min(k * 2, n); j++) {
			for(int p = 2; p <= j; p++) {
				(dp[i][j] += 1ll * dp[i - 1][j - p] * inv[p] % P) %= P;
			}
		}
	}
	return;
}

int main() {
	scanf("%d%d", &n, &k);
	init(k * 2);
	initDP();
	for(int i = 1; i <= k; i++) {
		int ans = 0;	
		for(int j = 0; j <= k; j++) {
			for(int p = j * 2; p <= min(n, 2 * k); p++) {
				if(p - j > i) continue;
				if((n & 1) ^ ((n - p + j) & 1) ^ (i & 1)) continue;
				ans = (ans + 1ll * dp[j][p] * ifac[j] % P * und[p] % P) % P;
			}
		}
		printf("%d%c", ans, " \n"[i == k]);
	}
	return 0;
}