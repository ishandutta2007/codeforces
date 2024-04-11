#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;

int n, k;
char B[Maxn][Maxn];
int res[Maxn][Maxn];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%s", B[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i + k <= n) {
				bool ok = true;
				for (int d = 0; d < k && ok; d++)
					ok = B[i + d][j] == '.';
				if (ok)
					for (int d = 0; d < k; d++)
						res[i + d][j]++;
			}
			if (j + k <= n) {
				bool ok = true;
				for (int d = 0; d < k && ok; d++)
					ok = B[i][j + d] == '.';
				if (ok)
					for (int d = 0; d < k; d++)
						res[i][j + d]++;
			}
		}
	ii ans = ii(0, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (res[i][j] > res[ans.first][ans.second]) ans = ii(i, j);
	printf("%d %d\n", ans.first + 1, ans.second + 1);
	return 0;
}