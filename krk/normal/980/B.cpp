#include <bits/stdc++.h>
using namespace std;

const int Maxm = 4;
const int Maxn = 1005;

int n, k;
bool tk[Maxm][Maxn];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i + 1 < Maxm && k >= 2; i++)
		for (int j = 1; j < n - 1 - j && k >= 2; j++) {
			tk[i][j] = tk[i][n - 1 - j] = true; k -= 2;
		}
	for (int i = 1; i + 1 < Maxm && k >= 1; i++) {
		tk[i][n / 2] = true; k--;
	}
	printf("YES\n");
	for (int i = 0; i < Maxm; i++) {
		for (int j = 0; j < n; j++)
			printf("%c", tk[i][j]? '#': '.');
		printf("\n");
	}
	return 0;
}