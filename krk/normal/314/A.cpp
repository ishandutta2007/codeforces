#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, k;
ll sum;

int main()
{
	scanf("%d %d", &n, &k);
	ll cur = 1ll;
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		if (ll(i - cur) * ll(n - i) > (sum - k) / ll(a) || ll(i - cur) * ll(n - i) * ll(a) > sum - k) {
			printf("%d\n", i); cur++;
		}
		else sum += ll(a) * ll(i - cur);
	}
	return 0;
}