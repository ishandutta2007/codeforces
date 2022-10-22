#include <cstdio>
#include <cstring>
using namespace std;

const int Maxn = 2005;

int n, m, k;
char B[Maxn][Maxn];

int Check(int r, int c, char need)
{
	return 0 <= r && r < n && 0 <= c && c < m && B[r][c] == need;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%s", B[i]);
	for (int j = 0; j < m; j++) {
		int res = 0;
		for (int i = 1; i < n; i++)
			res += Check(i, j - i, 'R') + Check(i, j + i, 'L') + Check(i + i, j, 'U');
		printf("%d%c", res, j + 1 < m? ' ': '\n');
	}
	return 0;
}