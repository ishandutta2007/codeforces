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
const int N = 3000 + 10, P = 1e9 + 7;
int n, d, pa[N];
int f[N][N];

int qpow(int a, int b) {
	int res = 1;
	for(; b; b >>= 1, a = 1ll * a * a % P) if(b & 1) res = 1ll * res * a % P;
	return res;
}

int main() {
	scanf("%d%d", &n, &d);
	for(int i = 2; i <= n; i++) scanf("%d", &pa[i]);
	for(int i = 1; i <= n; i++) fill(f[i] + 1, f[i] + n + 2, 1);
	for(int i = n; i >= 2; i--) {
		for(int j = 1; j <= n + 1; j++) {
			(f[i][j] += f[i][j - 1]) %= P;
			f[pa[i]][j] = 1ll * f[pa[i]][j] * f[i][j] % P;
		}
	}
	for(int i = 1; i <= n + 1; i++) (f[1][i] += f[1][i - 1]) %= P;
	int ans = 0;
	for(int i = 1; i <= n + 1; i++) {
		int dem = 1, num = 1;
		for(int j = 1; j <= n + 1; j++) {
			if(i == j) continue;
			dem = 1ll * dem * (d - j + P) % P;
			num = 1ll * num * (i - j + P) % P;
		}
		ans = (ans + 1ll * f[1][i] * dem % P * qpow(num, P - 2) % P) % P;
	}
	printf("%d\n", ans);
	return 0;
}