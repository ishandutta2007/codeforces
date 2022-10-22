#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n, m;
int B[Maxn][Maxn];

bool Check()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (i + 1 < n && abs(B[i][j] - B[i + 1][j]) == 1 ||
				j + 1 < m && abs(B[i][j] - B[i][j + 1]) == 1)
				return false;
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	if (n == 1) {
		int cur = 0;
		for (int i = 2; i <= m; i += 2)
			B[0][cur++] = i;
		for (int i = 1; i <= m; i += 2)
			B[0][cur++] = i;
	} else if (m == 1) {
		int cur = 0;
		for (int i = 2; i <= n; i += 2)
			B[cur++][0] = i;
		for (int i = 1; i <= n; i += 2)
			B[cur++][0] = i;
	} else
		for (int j = 0; j < m; j++)
			for (int i = 0; i < n; i++)
				B[i][j] = j + (i + j) % n * m + 1;
	if (Check())
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				printf("%d%c", B[i][j], j + 1 < m? ' ': '\n');
	else printf("-1\n");
	return 0;
}