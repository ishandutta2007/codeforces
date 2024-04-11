#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2005;

int n, a[101][101], A, B;

int main() {
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	scanf("%d%d%d", &n, &A, &B);
	memset(a, 0, sizeof(a));
	int AA = 1, BB = 2;
	for (int i = 1; i <= A; i++)
		for (int j = 1; j <= B; j++)
			if (!((i + j) & 1)) {
				if (AA <= n) {
					a[i][j] = AA;
					AA += 2;
				}
			} else {
				if (BB <= n) {
					a[i][j] = BB;
					BB += 2;
				}
			}
	if (AA <= n || BB <= n) {
		printf("-1\n");
	} else {
		for (int i = 1; i <= A; i++) {
			for (int j = 1; j <= B; j++) printf("%d ", a[i][j]);
			printf("\n");
		}
	}
}