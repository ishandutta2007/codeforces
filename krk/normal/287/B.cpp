#include <cstdio>
using namespace std;

typedef long long ll;

ll n;
int k;
int res;

int main()
{
	scanf("%I64d %d", &n, &k);
	n--; k--;
	if (n == 0) { printf("0\n"); return 0; }
	if (ll(k) * ll(k + 1ll) / 2ll < n) { printf("-1\n"); return 0; }
	int l = 1, r = k;
	while (l <= r) {
		int mid = l + r >> 1;
		if (ll(mid) * ll(2 * k - mid + 1) / 2ll >= n) { res = mid; r = mid - 1; }
		else l = mid + 1;
	}
	printf("%d\n", res);
	return 0;
}