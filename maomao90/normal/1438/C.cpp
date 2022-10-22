#include <bits/stdc++.h>
using namespace std;

int t;
int n, m;
int a[105][105];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] % 2 == (i + j) % 2) a[i][j]++;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}