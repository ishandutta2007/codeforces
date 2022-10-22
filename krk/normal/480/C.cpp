#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 5005;

int n, a, b, k;
int ways[Maxn][Maxn];
int res;

int main()
{
	scanf("%d %d %d %d", &n, &a, &b, &k);
	ways[0][a] = 1; ways[0][a + 1] = mod - 1;
	for (int i = 0; i < k; i++) {
		int cur = 0;
		for (int j = 1; j <= n; j++) {
			cur = (cur + ways[i][j]) % mod;
			if (j == b || cur == 0) continue;
			int d = abs(j - b);
			int l = max(1, j - (d - 1));
			int r = min(n + 1, j + d);
			ways[i + 1][l] = (ways[i + 1][l] + cur) % mod;
			ways[i + 1][j] = (ways[i + 1][j] - cur + mod) % mod;
			ways[i + 1][j + 1] = (ways[i + 1][j + 1] + cur) % mod;
			ways[i + 1][r] = (ways[i + 1][r] - cur + mod) % mod;
		}
	}
	int cur = 0;
	for (int j = 1; j <= n; j++) {
		cur = (cur + ways[k][j]) % mod;
		if (j == b || cur == 0) continue;
		res = (res + cur) % mod;
	}
	printf("%d\n", res);
	return 0;
}