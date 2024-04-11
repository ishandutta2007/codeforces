#include <bits/stdc++.h>
using namespace std;

const int Inf = 2000000000;
const int Maxn = 51;

int best[Maxn];
int T;

int main()
{
	fill(best, best + Maxn, Inf);
	for (int i = 0; i < 1 << 9; i++) {
		int res = 0;
		int sum = 0;
		for (int j = 0; j < 9; j++) if (i & 1 << j) {
			res = 10 * res + j + 1;
			sum += j + 1;
		}
		best[sum] = min(best[sum], res);
	}
	scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		printf("%d\n", best[n] < Inf? best[n]: -1);
	}
    return 0;
}