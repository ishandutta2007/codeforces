#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n, a, b;
char B[Maxn][Maxn];

int main()
{
	scanf("%d %d %d", &n, &a, &b);
	if (a != 1 && b != 1) { printf("NO\n"); return 0; }
	if ((n == 2 || n == 3) && a == 1 && b == 1) { printf("NO\n"); return 0; }
	printf("YES\n");
	for (int i = 0; i < n; i++)
		B[i][i] = '0';
	char cola = '1', colb = '0';
	if (b != 1) { swap(cola, colb); swap(a, b); }
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) if (i != j)
			B[i][j] = B[j][i] = colb;
	for (int i = a - 1; i + 1 < n; i++)
		B[i][i + 1] = B[i + 1][i] = cola;
	for (int i = 0; i < n; i++) {
		B[i][n] = '\0';
		printf("%s\n", B[i]);
	}
	return 0;
}