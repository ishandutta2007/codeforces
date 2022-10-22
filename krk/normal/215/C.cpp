#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, m, s;
ll res;

ll getWays(int y, int x) 
{
	if (y > n || x > m) return 0ll;
	return ll(n - y + 1) * ll(m - x + 1); 
}

int main()
{
	scanf("%d %d %d", &n, &m, &s);
	for (int a = 0; a <= n / 2; a++) if (s % (2 * a + 1) == 0) {
		int need = s / (2 * a + 1);
		if (need % 2 == 0) continue;
		int b = (need - 1) / 2;
		res += (2ll * ll(a + 1) * ll(b + 1) - 1ll) * getWays(2 * a + 1, 2 * b + 1);
	}
	for (int a = 0; a <= n / 2; a++)
		for (int b = 0; (2 * a + 1) * (2 * b + 1) < s; b++) {
			int slft = s - (2 * a + 1) * (2 * b + 1);
			for (int c = a + 1; c <= n / 2; c++) if (slft % (2 * (c - a)) == 0) {
				int need = slft / (2 * (c - a));
				if (need % 2 == 0) continue;
				int d = (need - 1) / 2;
				if (d >= b) continue;
				res += getWays(2 * c + 1, 2 * b + 1);
			}
			for (int d = b + 1; d <= m / 2; d++) if (slft % (2 * (d - b)) == 0) {
				int need = slft / (2 * (d - b));
				if (need % 2 == 0) continue;
				int c = (need - 1) / 2;
				if (c >= a) continue;
				res += getWays(2 * a + 1, 2 * d + 1);
			}
		}
	printf("%I64d\n", res);
	return 0;
}