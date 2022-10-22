#include <cstdio>
using namespace std;

typedef long long ll;

ll x, y, m;
ll res;

int main()
{
	scanf("%I64d %I64d %I64d", &x, &y, &m);
	if (x >= m || y >= m) printf("0\n");
	else if (x <= 0ll && y <= 0ll) printf("-1\n");
	else {
		if (x <= 0ll) { ll d = -x / y; x += d * y; res += d; }
		else if (y <= 0ll) { ll d = -y / x; y += d * x; res += d; }
		while (x < m && y < m) {
			if (x < y) x = x + y;
			else y = x + y;
			res++;
		}
		printf("%I64d\n", res);
	}
	return 0;
}