#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxm = 12;

int n, k;
int tot;
int cg[Maxm];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		tot += a / 10;
		int md = (10 - a % 10) % 10;
		if (md) {
			cg[md]++; a += md;
		}
		while (a < 100) {
			cg[10]++; a += 10;
		}
	}
	for (int i = 1; i < Maxm; i++) {
		int tk = min(cg[i], k / i);
		tot += tk; k -= i * tk;
	}
	printf("%d\n", tot);
	return 0;
}