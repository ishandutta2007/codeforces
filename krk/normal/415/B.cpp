#include <cstdio>
using namespace std;

typedef long long ll;

int n, a, b;

int main()
{
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		ll cost = ll(x) * a / b;
		ll s = cost * b;
		printf("%d%c", x - int(s / a + (s % a > 0)), i + 1 < n? ' ': '\n');
	}
	return 0;
}