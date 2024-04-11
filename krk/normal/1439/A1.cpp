#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;

int T;
int n, m;
char B[Maxn][Maxn];
vector <ii> res1, res2, res3;

void Flip(int r, int c) { B[r][c] = B[r][c] == '0'? '1': '0'; }

void Add(int a, int b, int c, int d, int e, int f)
{
	Flip(a, b);
	Flip(c, d);
	Flip(e, f);
	res1.push_back(ii(a, b));
	res2.push_back(ii(c, d));
	res3.push_back(ii(e, f));
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%s", B[i] + 1);
		res1.clear(); res2.clear(); res3.clear();
		for (int i = 1; i + 2 <= n; i++)
			for (int j = 1; j <= m; j += 2) {
				int a = j, b = j + 1;
				if (b > m) a--, b--;
				if (B[i][a] == '1' && B[i][b] == '1')
					Add(i, a, i, b, i + 1, a);
				else if (B[i][a] == '1')
					Add(i, a, i + 1, a, i + 1, b);
				else if (B[i][b] == '1')
					Add(i, b, i + 1, a, i + 1, b);
			}
		for (int j = 1; j + 1 <= m; j++)
			if (B[n - 1][j] == '1' && B[n][j] == '1')
				Add(n - 1, j, n, j, n - 1, j + 1);
			else if (B[n - 1][j] == '1')
				Add(n - 1, j, n - 1, j + 1, n, j + 1);
			else if (B[n][j] == '1')
				Add(n, j, n - 1, j + 1, n, j + 1);
		if (B[n - 1][m] == '1' && B[n][m] == '1') {
			Add(n - 1, m, n - 1, m - 1, n, m - 1);
			Add(n, m, n - 1, m - 1, n, m - 1);
		} else if (B[n - 1][m] == '1') {
			Add(n - 1, m, n - 1, m - 1, n, m - 1);
			Add(n - 1, m, n - 1, m - 1, n, m);
			Add(n - 1, m, n, m - 1, n, m);
		} else if (B[n][m] == '1') {
			Add(n, m, n - 1, m - 1, n, m - 1);
			Add(n, m, n - 1, m - 1, n - 1, m);
			Add(n, m, n - 1, m, n, m - 1);
		}
		printf("%d\n", int(res1.size()));
		for (int i = 0; i < res1.size(); i++)
			printf("%d %d %d %d %d %d\n", res1[i].first, res1[i].second, res2[i].first, res2[i].second, res3[i].first, res3[i].second);
	}
    return 0;
}