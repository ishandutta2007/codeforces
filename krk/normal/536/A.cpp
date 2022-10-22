#include <cstdio>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000ll;

int a, b, n;
int l, t, m;

int main()
{
	scanf("%d %d %d", &a, &b, &n);
	while (n--) {
		scanf("%d %d %d", &l, &t, &m);
		ll mult = ll(t) * m;
		ll r = l - 1;
		ll L = l, R = Inf;
		while (L <= R) {
			ll M = L + R >> 1ll;
			ll A = a + ll(b) * (l - 1);
			ll B = a + ll(b) * (M - 1);
			if (B <= t && A + B <= 2ll * mult / (M - l + 1)) {
				r = M; L = M + 1;
			} else R = M - 1;
		}
		if (r < l) printf("-1\n");
		else printf("%I64d\n", r);
	}
	return 0;
}