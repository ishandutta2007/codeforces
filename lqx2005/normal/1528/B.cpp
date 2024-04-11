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
const int N = 1e6 + 10, P = 998244353;
int n;
int dp[N], f[N];
int qpow(int a, int b, int c = 1) { for(; b; b >>= 1, a = 1ll * a * a % P) if(b & 1) c = 1ll * c * a % P; return c; }

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) for(int j = i; j <= n; j += i) f[j]++;
	dp[1] = 1;
	for(int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] + f[i]) % P;
		dp[i] = (dp[i] + dp[i - 1]) % P;
	}
	printf("%d\n", (dp[n] - dp[n - 1] + P) % P);
	return 0;
}