#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 52;
const int mod = 1000000007;

int pw[Maxn];
int n, p;
int ways[Maxn][Maxn][2][2][2];

int main()
{
	pw[0] = 1;
	for (int i = 1; i < Maxn; i++)
		pw[i] = 2ll * pw[i - 1] % mod;
	scanf("%d %d", &n, &p);
	ways[0][0][0][0][0] = 1;
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		for (int w = 0; w <= i; w++) {
			int b = i - w;
			for (int w1 = 0; w1 < 2; w1++)
				for (int b1 = 0; b1 < 2; b1++)
					for (int cur = 0; cur < 2; cur++) if (ways[i][w][w1][b1][cur]) {
						int mult = ways[i][w][w1][b1][cur];
						if (a == -1 || a == 0)
							if (b1 == 1) {
								int add = ll(pw[b - 1]) * pw[w] % mod;
								ways[i + 1][w + 1][1][b1][cur ^ 1] = (ways[i + 1][w + 1][1][b1][cur ^ 1] + ll(mult) * add) % mod;
								ways[i + 1][w + 1][w1][b1][cur] = (ways[i + 1][w + 1][w1][b1][cur] + ll(mult) * add) % mod;
							} else {
								int add = ll(pw[b]) * pw[w] % mod;
								ways[i + 1][w + 1][1][b1][cur ^ 1] = (ways[i + 1][w + 1][1][b1][cur ^ 1] + ll(mult) * add) % mod;
							}
						if (a == -1 || a == 1)
							if (w1 == 1) {
								int add = ll(pw[w - 1]) * pw[b] % mod;
								ways[i + 1][w][w1][1][cur ^ 1] = (ways[i + 1][w][w1][1][cur ^ 1] + ll(mult) * add) % mod;
								ways[i + 1][w][w1][b1][cur] = (ways[i + 1][w][w1][b1][cur] + ll(mult) * add) % mod;
							} else {
								int add = ll(pw[w]) * pw[b] % mod;
								ways[i + 1][w][w1][1][cur ^ 1] = (ways[i + 1][w][w1][1][cur ^ 1] + ll(mult) * add) % mod;
							}
					}
		}
	}
	int res = 0;
	for (int w = 0; w <= n; w++)
		for (int w1 = 0; w1 < 2; w1++)
			for (int b1 = 0; b1 < 2; b1++)
				res = (res + ways[n][w][w1][b1][p]) % mod;
	printf("%d\n", res);
	return 0;
}