#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pii pair<int, int>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 200 + 10, SQ = 20 + 5;
int n, M, sq;
int fac[N], ifac[N];
int f[SQ][N][N];
void Add(int &x, int y) {if((x += y) >= M && (x -= M)); }
int power(int a, int b, int c = 1) {
	for(; b; b >>= 1, a = 1ll * a * a % M)
		if(b & 1)
			c = 1ll * c * a % M;
	return c;
}

int main() {
	scanf("%d%d", &n, &M);
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % M;
	ifac[n] = power(fac[n], M - 2);
	for(int i = n - 1; i >= 0; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % M;
	int ans = 0;
	for(int i = n + 1; i >= 1; i--) {
		memset(f, 0, sizeof(f));
		f[0][0][0] = 1;
		for(int j = 0; j <= n + 1 - i; j++) {
			for(int k = 0; k <= n; k++) {
				for(int m = 0; m <= i; m++) {
					if(!f[j][k][m]) continue;
					if(j) Add(f[j + 1][k][m], f[j][k][m]);
					for(int l = 1; l * (i + j) <= i * (i + j - k) - m && m + l * j <= i && k + l <= n; l++) {
						Add(f[j + 1][k + l][m + l * j], 1ll * f[j][k][m] * ifac[l] % M);
					}
				}
			}
		}
		int sum = 0;
		for(int j = 0; j <= i; j++) Add(sum, 1ll * fac[n] * f[n + 2 - i][n][j] % M);
		if(sum == 0) break;
		Add(ans, sum);
	}
	printf("%d\n", ans);
	return 0;
}