#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 1000005;
const int Maxd = 10;

int n;
int best[Maxn];
bool digs[Maxd];

void getDigs(int num)
{
	fill(digs, digs + Maxd, false);
	do {
		digs[num % 10] = true;
		num /= 10;
	} while (num);
}

int main()
{
	scanf("%d", &n);
	best[0] = 0;
	for (int i = 1; i <= n; i++) {
		best[i] = Inf;
		getDigs(i);
		for (int j = 0; j < Maxd; j++) if (digs[j])
			best[i] = min(best[i], best[i - j] + 1);
	}
	printf("%d\n", best[n]);
	return 0;
}