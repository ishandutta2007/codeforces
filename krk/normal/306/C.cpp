#include <cstdio>
using namespace std;

typedef long long ll;

const int mod = 1000000009;
const int Maxn = 4005;

int fact[Maxn];
int C[Maxn][Maxn];
int n, w, b;
int res;

int main()
{
	fact[0] = 1;
	for (int i = 1; i < Maxn; i++) fact[i] = ll(fact[i - 1]) * ll(i) % ll(mod);
	for (int i = 0; i < Maxn; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	scanf("%d %d %d", &n, &w, &b);
	for (int forb = 1; forb <= n - 2; forb++) {
		int ways = ll(fact[b]) * ll(C[b - 1][forb - 1]) % ll(mod);
		int forw = n - forb;
		ways = ll(ways) * ll(fact[w]) % ll(mod) * ll(C[w - 1][forw - 1]) % ll(mod) * ll(forw - 1) % ll(mod);
		res = (res + ways) % mod;
	}
	printf("%d\n", res);
	return 0;
}