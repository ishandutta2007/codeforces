#include <cstdio>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int mod = 1000000007;
const int Maxn = 1000005;

int n;
int ways[Maxn][2][2];

int Get(int n, int cur, int need)
{
	if (n == 0) return 0;
	if (ways[n][cur][need] == -1)
		ways[n][cur][need] = cur == need? (1 + Get(n - 1, 1 - cur, 1 - need) + Get(n - 1, 1 - cur, need)) % mod: Get(n - 1, 1 - cur, need);
	return ways[n][cur][need];
}

int main()
{
	fill((int*)ways, (int*)ways + Maxn * 2 * 2, -1);
	scanf("%d", &n);
	printf("%d\n", (Get(n, 0, 0) + Get(n, 0, 1)) % mod);
	return 0;
}