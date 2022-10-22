#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int B[Maxn][Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		fill((int*)B, (int*)B + Maxn * Maxn, 0);
		for (int i = 0; i < n; i++) {
			B[i][i] = B[i][(i + 1) % n] = 1;
			for (int j = 0; j < n; j++)
				printf("%d%c", B[i][j], j + 1 < n? ' ': '\n');
		}
	}
    return 0;
}