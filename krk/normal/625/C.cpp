#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 505;

int n, k;
int B[Maxn][Maxn];

int main()
{
	scanf("%d %d", &n, &k);
	int cur = 1;
	for (int j = 1; j < k; j++)
		for (int i = 1; i <= n; i++)
			B[i][j] = cur++;
	for (int i = 1; i <= n; i++)
		for (int j = k; j <= n; j++)
			B[i][j] = cur++;
	ll sum = 0;
	for (int i = 1; i <= n; i++)
		sum += B[i][k];
	printf("%I64d\n", sum);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			printf("%d%c", B[i][j], j + 1 <= n? ' ': '\n');
	return 0;
}