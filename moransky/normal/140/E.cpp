#include <iostream>
#include <cstdio>
 
using namespace std;
 
typedef long long LL;
 
const int N = 1000005, M = 5005;
 
int n, m, P, fact[M], A[M], l[N], L, f[M][M], g[2][M];
 
int main() {
	scanf("%d%d%d", &n, &m, &P);
	for (int i = 1; i <= n; i++) scanf("%d", l + i), L = max(L, l[i]);
	fact[0] = A[0] = 1;
	for (int i = 1; i <= L; i++) fact[i] = (LL)fact[i - 1] * i % P;
	for (int i = 1; i <= L; i++) A[i] = (LL)A[i - 1] * (m - i + 1) % P;
	f[1][1] = 1;
	for (int i = 2; i <= L; i++) {
		for (int j = 1; j <= i; j++) {
			f[i][j] = (f[i - 1][j - 1] + (LL)f[i - 1][j] * (j - 1)) % P;
		}
	}
	int s = 0;
	for (int j = 1; j <= min(m, l[1]); j++)
		g[1][j] = (LL)f[l[1]][j] * A[j] % P, (s += g[1][j]) %= P;
 
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= min(m, l[i]); j++) {
			g[i & 1][j] = ((LL)s * A[j] % P - (j > l[i - 1] ? 0 : (LL)g[(i - 1) & 1][j] * fact[j] % P) + P) % P * f[l[i]][j] % P;
		}
		s = 0;
		for (int j = 1; j <= min(m, l[i]); j++) (s += g[i & 1][j]) %= P;
	}
 
	printf("%d\n", s);
	return 0;
}