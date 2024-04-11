#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
#define MAXN 505

int n, m;
int a[505][505];
int dp[MAXN][5];
ii diff = MP(-1, -1);

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int prv = 0;
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			if (j == 0) prv = a[i][j];
			else if (a[i][j] != prv) diff = MP(i, j);
		}
	}
	int cur = 0;
	for (int i = 0; i < n; i++) {
		cur ^= a[i][0];
	}
	if (cur != 0) {
		printf("TAK\n");
		for (int i = 0; i < n; i++) {
			printf("1 ");
		}
		printf("\n");
	} else {
		if (diff == MP(-1, -1)) {
			printf("NIE\n");
		} else {
			printf("TAK\n");
			for (int i = 0; i < n; i++) {
				if (i == diff.FI) printf("%d ", diff.SE + 1);
				else printf("1 ");
			}
		}
	}
	return 0;
}