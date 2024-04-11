#include <bits/stdc++.h>
using namespace std;

#define FI first
#define SE second
#define mp make_pair
typedef pair <int, int> ii;
#define MAXN 70000

int n;
ii xorj[MAXN];
int ans[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		printf("XOR %d %d\n", 1, i + 1);
		fflush(stdout);
		int x; scanf("%d", &x);
		xorj[i - 1] = mp(x, i + 1);
	}
	sort(xorj, xorj + n - 1);
	int same = -1, same2 = -1;
	for (int i = 0; i < n - 1; i++) {
		if (xorj[i].FI == 0) {
			same2 = i;
			break;
		}
		if (i != 0 && xorj[i].FI == xorj[i - 1].FI) {
			same = i - 1;
			break;
		}
	}
	if (same == -1 && same2 == -1) {
		int i = 1, j1 = xorj[0].SE, j2 = xorj[1].SE;
		int x1, x2;
		printf("AND %d %d\n", i, j1);
		fflush(stdout);
		scanf("%d", &x1);
		printf("AND %d %d\n", i, j2);
		fflush(stdout);
		scanf("%d", &x2);
		ans[1] = x1 | x2;
	} else {
		int i, j;
		if (same2 != -1) {
			i = 1, j = xorj[same2].SE;
		}
		else {
			i = xorj[same].SE, j = xorj[same + 1].SE;
		}
		printf("AND %d %d\n", i, j);
		fflush(stdout);
		int x; scanf("%d", &x);
		ans[1] = x ^ xorj[same].FI;
	}
	for (int k = 0; k < n - 1; k++) {
		ans[xorj[k].SE] = ans[1] ^ xorj[k].FI;
	}
	printf("!");
	for (int i = 1; i <= n; i++) {
		printf(" %d", ans[i]);
	}
	printf("\n");
	fflush(stdout);
	return 0;
}