#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;

int n;
int my[Maxn][Maxn];
int mx[Maxn][Maxn];
int q;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &my[i][0]); mx[i][0] = my[i][0];
	}
	for (int l = 1; l <= n; l++)
		for (int i = 1; i + l <= n; i++) {
			my[i][l] = (my[i][l - 1] ^ my[i + 1][l - 1]);
			mx[i][l] = max(my[i][l], max(mx[i][l - 1], mx[i + 1][l - 1]));
		}
	scanf("%d", &q);
	while (q--) {
		int l, r; scanf("%d %d", &l, &r);
		printf("%d\n", mx[l][r - l]);
	}
	return 0;
}