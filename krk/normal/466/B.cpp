#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 9000000000000000000ll;

int n, a, b;
ll need;
ll best = Inf;
ll bi, bj;

ll Get(ll a)
{
	ll b = need / a;
	if (a * b < need) b++;
	return b;
}

int main()
{
	scanf("%d %d %d", &n, &a, &b);
	if (6 * ll(n) <= ll(a) * b) printf("%I64d\n%d %d\n", ll(a) * b, a, b);
	else {
		need = 6 * ll(n);
		for (int i = 0; i <= 100000; i++) {
			ll cb = max(Get(a + i), ll(b));
			if (cb * (a + i) < best) { best = cb * (a + i); bi = a + i; bj = cb; }
			ll ca = max(Get(b + i), ll(a));
			if (ca * (b + i) < best) { best = ca * (b + i); bi = ca; bj = b + i; }
		}
		printf("%I64d\n%I64d %I64d\n", best, bi, bj);
	}
	return 0;
}