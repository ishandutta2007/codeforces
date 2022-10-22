#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 505;

int T;
int n, m;
char B[Maxn][Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%s", B[i]);
		if (n == 1) { printf("%s\n", string(m, 'X').c_str()); continue; }
		int col = 0;
		while (col + 3 < m) col += 3;
		for (int j = 0; j <= col; j += 3) {
			for (int i = 0; i < n; i++)
				B[i][j] = 'X';
			if (j < col)
				if (B[1][j + 1] == 'X' || B[1][j + 2] == 'X')
					B[1][j + 1] = B[1][j + 2] = 'X';
				else B[0][j + 1] = B[0][j + 2] = 'X';
		}
		if (col + 3 == m) {
			int lst = n;
			for (int i = n - 1; i >= 0; i--)
				if (B[i][col + 1] == 'X') {
					lst--;
					while (lst > i && B[lst][col + 2] != 'X')
						lst--;
					while (lst > i) {
						lst--;
						B[lst][col + 2] = 'X';
					}
				}
			if (lst >= 2) {
				B[0][col + 1] = 'X';
				lst--;
				while (lst > 0 && B[lst][col + 2] != 'X')
					lst--;
				while (lst > 0) {
					lst--;
					B[lst][col + 2] = 'X';
				}
			} else if (lst == 1 && B[0][col + 2] == 'X')
				B[0][col + 2] = B[1][col + 2] = 'X';
		}
		for (int i = 0; i < n; i++)
			printf("%s\n", B[i]);
	}
    return 0;
}