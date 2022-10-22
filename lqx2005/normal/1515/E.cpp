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

typedef long long LL;
typedef pair<int, int> par;
typedef unsigned long long uLL;
typedef double db;
const int N = 400 + 10;
int n, P;
int fac[N], ifac[N];
int dp[N][N];

int qpow(int a, int b, int c = 1) {for(; b; b >>= 1, a = 1ll * a * a % P) if(b & 1) c = 1ll * c * a % P; return c;}

void initmath(int n) {
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % P;
	ifac[n] = qpow(fac[n], P - 2);
	for(int i = n - 1; i >= 0; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % P;
	return;
}

int main() {
	scanf("%d%d", &n, &P);
	initmath(n);
	dp[0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = i + 2; j <= n + 1; j++) {
			int pw = 1;
			for(int k = 1; k < j - i - 1; k++) pw = 1ll * pw * 2 % P;
			for(int k = 0; k <= n - (j - i - 1); k++) {
				(dp[j][k + j - i - 1] += 1ll * dp[i][k] * ifac[j - i - 1] % P * pw % P) %= P;
			}
		}
	}
	int res = 0;
	for(int i = 1; i <= n; i++) (res += 1ll * dp[n + 1][i] * fac[i] % P) %= P;
	printf("%d\n", res);
	return 0;
}