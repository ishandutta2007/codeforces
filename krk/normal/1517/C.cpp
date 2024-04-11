#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;

int n;
int A[Maxn];
int B[Maxn][Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &A[i]);
	for (int i = n; i >= 1; i--) {
		int nd = A[i];
		int r = i, c = i;
		while (true) {
			B[r][c] = A[i];
			nd--;
			if (nd == 0) break;
			if (r + 1 <= n && B[r + 1][c] == 0) r++;
			else c--;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			printf("%d%c", B[i][j], j + 1 <= i? ' ': '\n');
    return 0;
}