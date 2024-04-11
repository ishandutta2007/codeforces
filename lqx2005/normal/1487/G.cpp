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
const int N = 400 + 10, P = 998244353;
int n;
int c[26];
int f[N][N][2], g[N][N][N][3], s[N][N];

int add(int x) { return x >= P ? x - P : x; }
int sub(int x) { return x < 0 ? x + P : x; }
void Add(int &x, int y) { if((x += y) >= P && (x -= P)); }
void Sub(int &x, int y) { if((x -= y) < 0 && (x += P)); }

int qpow(int a, int b) {
	int res = 1;
	for(; b; b >>= 1, a = 1ll * a * a % P) if(b & 1) res = 1ll * res * a % P;
	return res;
}

void DP1(int n) {
	f[1][1][1] = 1, f[1][0][0] = 25;
	for(int i = 1; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			for(int k = 0; k <= 1; k++) {
				for(int l = 0; l <= 1; l++) {
					if(k && l) continue;
					if(l) Add(f[i + 1][j + 1][l], f[i][j][k]);
					else Add(f[i + 1][j][l], 1ll * f[i][j][k] * (25 - (!k)) % P);
				}
			}
		}
	}
	return;
}

void DP2(int n) {
	g[1][0][0][0] = 24, g[1][1][0][1] = g[1][0][1][2] = 1;
	for(int i = 1; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			for(int k = 0; k <= i - j; k++) {
				for(int l = 0; l <= 2; l++) {
					for(int r = 0; r <= 2; r++) {
						if(l == r && l && r) continue;
						int nj = j + (r == 1), nk = k + (r == 2);
						if(!r) {
							Add(g[i + 1][nj][nk][r], 1ll * g[i][j][k][l] * (24 - (!l)) % P);
						} else {
							Add(g[i + 1][nj][nk][r], g[i][j][k][l]);
						}
					}
				}
			}
		}
	}
	for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) for(int k = 0; k <= n; k++) Add(g[i][j][k][0], add(g[i][j][k][1] + g[i][j][k][2]));
	return;
}

int S(int n) { return 26ll * qpow(25, n - 1) % P; }

int main() {
	scanf("%d", &n);
	for(int i = 0; i < 26; i++) scanf("%d", &c[i]);
	DP1((n + 1) / 2), DP2((n + 1) / 2);
	int ans = 1ll * S(n / 2) * S(n - n / 2) % P;
	for(int i = n; i >= 0; i--) {
		for(int j = n; j >= 0; j--) {
			s[i][j] = g[n - n / 2][i][j][0];
			Add(s[i][j], sub(add(s[i][j + 1] + s[i + 1][j]) - s[i + 1][j + 1]));
		}
	}
	for(int i = 0; i < 26; i++) {
		int s = 0;
		for(int j = c[i] + 1; j <= n; j++) Add(s, add(f[n - n / 2][j][0] + f[n - n / 2][j][1]));
		for(int j = 0; j <= n / 2; j++) {
			Sub(ans, 1ll * add(f[n / 2][j][0] + f[n / 2][j][1]) * s % P);
			if(j <= c[i]) Add(s, add(f[n - n / 2][c[i] - j][0] + f[n - n / 2][c[i] - j][1]));
		}
	}
	for(int i = 0; i < 26; i++) {
		for(int j = i + 1; j < 26; j++) {
			for(int k = 0; k <= n / 2; k++) {
				for(int l = 0; l <= n / 2 - k; l++) {
					Add(ans, 1ll * g[n / 2][k][l][0] * s[max(0, c[i] + 1 - k)][max(0, c[j] + 1 - l)] % P);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}