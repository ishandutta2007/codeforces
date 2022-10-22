#include <bits/stdc++.h>
using namespace std;

int T;
int n, x, y;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &n, &x, &y);
		int best = 1000000000, st, dif;
		for (int i = 1; i <= y - x; i++) if ((y - x) % i == 0) {
			int hm = (y - x) / i + 1;
			if (hm > n) continue;
			int candst = x, canden = x + (n - 1) * i;
			while (candst > i && canden > y) {
				candst -= i; canden -= i;
			}
			if (canden < best) { best = canden; st = candst; dif = i; }
		}
		for (int i = st; i <= best; i += dif)
			printf("%d%c", i, i < best? ' ': '\n');
	}
    return 0;
}