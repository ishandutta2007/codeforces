#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
ll res;

int main()
{
	scanf("%d", &n);
	ll cur = 1;
	for (int i = 1; cur <= n; cur *= 10ll, i++) {
		ll tk = min(cur * 10ll, ll(n + 1));
		res += (tk - cur) * i;
	}
	printf("%I64d\n", res);
	return 0;
}