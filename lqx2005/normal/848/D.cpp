#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
using namespace std;
typedef double db;
const int S = 50 + 10, P = 1e9 + 7;
int N, M;
int fac[S], ifac[S];
int dp1[S][S][S][S], dp2[S][S];

int power(int a, int b, int c = 1) {
	for(; b; b >>= 1, a = 1ll * a * a % P)
		if(b & 1)
			c = 1ll * c * a % P;
	return c;
}

void initmath(int n) {
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % P;
	ifac[n] = power(fac[n], P - 2);
	for(int i = n - 1; i >= 0; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % P;
	return;
}

void Add(int &x, int y) { if((x += y) >= P) x -= P; }
void Sub(int &x, int y) { if((x -= y) < 0) x += P; } 

int DP1(int n, int m, int a, int b);
int DP2(int n, int m) {
	if(dp2[n][m] != -1) return dp2[n][m];
	if(m < 1) return 0;
	int &res = dp2[n][m];
	res = 0;
	for(int i = 2; i < n; i++) {
		for(int j = m + 1; j <= n - 1; j++) {
			Add(res, 1ll * DP1(i, j, i - 2, j) * DP1(n - i + 1, m, n - i - 1, m) % P);
			Add(res, 1ll * DP1(i, m, i - 2, m) * DP1(n - i + 1, j, n - i - 1, j) % P);
		}
		Add(res, 1ll * DP1(i, m, i - 2, m) * DP1(n - i + 1, m, n - i - 1, m) % P);
	}
//	cout << n <<" " << m <<" " << res << endl;
	return res;
}

int DP1(int n, int m, int a, int b) {
	if(m < 1) return 0; 
	if(m == 1) return n == 2;
	if(a <= 0 || b <= 0) return 0;
	if(dp1[n][m][a][b]!= -1) return dp1[n][m][a][b];
	int &res = dp1[n][m][a][b];
	int na = a, nb = b;
	nb--;
	if(nb == 0) nb = m - 1, na--;
	res = DP1(n, m, na, nb);
	int num = DP2(a + 2, b), prod = 1;
	for(int i = 1; i * a + 2 <= n && i * b < m; i++) {
		prod = 1ll * prod * (num + i - 1) % P;
		int A = min(na, n - i * a - 2), B;
		if(A == na) B = min(nb, m - i * b - 1);
		else B = m - i * b - 1;
		Add(res, 1ll * DP1(n - i * a, m - i * b, A, B) * prod % P * ifac[i] % P);
	}
	return res;
}
int main() {
	memset(dp1, -1, sizeof(dp1));
	memset(dp2, -1, sizeof(dp2));
	scanf("%d%d", &N, &M);
	initmath(N);
	printf("%d\n", DP1(N + 2, M, N, M));
	return 0;
}