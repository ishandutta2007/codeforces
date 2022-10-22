#include <cstdio>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 605;

int n;
int L[Maxn], R[Maxn];
bool dp[Maxn][Maxn];
int par[Maxn][Maxn];

void Solve(int v, int len)
{
	if (len == 0) return;
	int k = par[v][len];
	printf("("); Solve(v + 1, k); printf(")"); Solve(v + k + 1, len - 1 - k);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &L[i], &R[i]);
	for (int i = 0; i <= n; i++) dp[i][0] = true;
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < n - i; j++)
			for (int k = 0; k <= j; k++) 
				if (L[i] <= 2 * k + 1 && 2 * k + 1 <= R[i] && dp[i + 1][k] && dp[i + k + 1][j - k]) {
					dp[i][j + 1] = true; par[i][j + 1] = k; break;
				}
	if (dp[0][n]) { Solve(0, n); printf("\n"); }
	else printf("IMPOSSIBLE\n");
	return 0;
}