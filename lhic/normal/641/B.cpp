#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

int n, m, q;
int a[120][120];
int ans[100000];

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			a[i][j] = i * m + j;
	for (int i = 0; i < q; ++i) {
		int t;

		scanf("%d", &t);
		if (t == 1) {
			int r;
			scanf("%d", &r);
			--r;
			int tmp = a[r][0];
			for (int j = 0; j < m - 1; ++j)
				a[r][j] = a[r][j + 1];
			a[r][m - 1] = tmp;
		}
		else if (t == 2) {
			int c;
			scanf("%d", &c);
			--c;
			int tmp = a[0][c];
			for (int j = 0; j < n - 1; ++j)
				a[j][c] = a[j + 1][c];
			a[n - 1][c] = tmp;
		}
		else {
			int r, c, x;
			scanf("%d%d%d", &r, &c, &x);
			--r;
			--c;
			ans[a[r][c]] = x;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			printf("%d ", ans[i * m + j]);
		printf("\n");
	}
	return 0;
}