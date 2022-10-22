#include <cstdio>
using namespace std;

typedef long long ll;

int t;
int n;

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		ll res = ll(n + 1) * n / 2;
		int cur = 1;
		while (cur <= n) {
			res -= 2 * cur;
			cur *= 2;
		}
		printf("%I64d\n", res);
	}
	return 0;
}