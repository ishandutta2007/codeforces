#include <cstdio>
using namespace std;

typedef long long ll;

int n, x, y;
int a;

int main()
{
	scanf("%d %d %d", &n, &x, &y);
	while (n--) {
		scanf("%d", &a);
		a = a % (x + y);
		ll lef = 0, rig = ll(x) * y;
		ll res = -1;
		while (lef <= rig) {
			ll m = lef + rig >> 1ll;
			ll got = m / y + m / x;
			if (got >= a) { res = m; rig = m - 1; }
			else lef = m + 1;
		}
		if (res % y == 0 && res % x == 0) printf("Both\n");
		else if (res % y == 0) printf("Vanya\n");
		else printf("Vova\n");
	}
	return 0;
}