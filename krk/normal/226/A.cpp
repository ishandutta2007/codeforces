#include <cstdio>
using namespace std;

typedef long long ll;

int n, m;

int main()
{
	scanf("%d %d", &n, &m);
	int res = 1, a = 3;
	while (n) {
		if (n & 1) res = ll(res) * ll(a) % ll(m);
		n >>= 1; a = ll(a) * ll(a) % ll(m);
	}
	res = (res - 1 + m) % m;
	printf("%d\n", res);
	return 0;
}