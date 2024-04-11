#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;

int T;
int n, m;
char B[Maxn][Maxn];
int vals[Maxn][Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%s", B[i]);
			int lst = 0;
			for (int j = 0; j < m; j++) {
				if (B[i][j] == '.') lst = 0;
				else lst++;
				vals[i][j] = lst;
			}
		}
		int res = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				for (int d = 0; i + d < n && j + d < m && vals[i + d][j + d] >= 2 * d + 1; d++)
					res++;
		printf("%d\n", res);
	}
    return 0;
}