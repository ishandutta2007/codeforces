#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 505;

ll mem[Maxn];
ll pmem[Maxn][Maxn];
int n, m, mod;
char B[Maxn][Maxn];
int need, ones, twos;
ll dp[2][Maxn];
int cur;

bool Check()
{
	need = n - m;
	for (int j = 0; j < n; j++) {
		int res = 0;
		for (int i = 0; i < m; i++)
			res += B[i][j] == '1';
		if (res > 2) return false;
		if (res == 1) ones++;
		if (res == 0) twos++;
	}
	return true;
}

int main()
{
	for (int i = 0; i < Maxn; i++)
		mem[i] = i * (i - 1) / 2;
	for (int i = 0; i < Maxn; i++)
		for (int j = 0; j < Maxn; j++)
			pmem[i][j] = i * j;
	scanf("%d %d %d", &n, &m, &mod);
	for (int i = 0; i < m; i++)
		scanf("%s", &B[i]);
	if (!Check()) { printf("0\n"); return 0; }
	dp[cur][0] = 1;
	for (int r = 1; r <= need; r++) {
		cur = !cur;
		for (int j = 0; j <= r; j++) {
			int i = 2 * r - 2 * j;
			if (i > n) continue;
			dp[cur][j] = 0;
			if (i >= 2) dp[cur][j] += mem[i] * dp[!cur][j];
			if (j >= 2) dp[cur][j] += mem[j] * dp[!cur][j - 2];
			if (i >= 1 && j >= 1) dp[cur][j] += pmem[i][j] * dp[!cur][j - 1];
			dp[cur][j] %= mod;
		}
	}
	printf("%I64d\n", dp[cur][twos]);
	return 0;
}