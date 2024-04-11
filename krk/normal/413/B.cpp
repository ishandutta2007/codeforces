#include <cstdio>
using namespace std;

const int Maxn = 20005;
const int Maxm = 12;

int n, m, k;
char B[Maxn][Maxm];
int inch[Maxm];
int my[Maxn];

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf(" %c", &B[i][j]);
	while (k--) {
		int x, y; scanf("%d %d", &x, &y);
		my[x]++; inch[y]++;
	}
	for (int i = 1; i <= n; i++) {
		int res = -my[i];
		for (int j = 1; j <= m; j++)
			if (B[i][j] == '1') res += inch[j];
		printf("%d%c", res, i + 1 <= n? ' ': '\n');
	}
	return 0;
}