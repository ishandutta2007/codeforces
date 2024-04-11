#include <cstdio>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 4005;

int C[Maxn][Maxn];
int n;
int f[Maxn], g[Maxn];

int main()
{
	for (int i = 0; i < Maxn; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	scanf("%d", &n);
	f[0] = 1; g[0] = 1;
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1];
		for (int j = 1; j <= i; j++) {
			f[i] = (f[i] + ll(C[i - 1][j - 1]) * f[i - j]) % mod;
			g[i] = (g[i] + ll(C[i - 1][j - 1]) * g[i - j]) % mod;
		}
	}
	printf("%d\n", (f[n] - g[n] + mod) % mod);
	return 0;
}