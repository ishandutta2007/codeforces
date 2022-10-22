#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int a, b, c, l;
ll res;

ll C(int n, int k)
{
	ll res = 1;
	for (int i = 1; i <= k; i++)
		res *= ll(n + i);
	for (int i = 1; i <= k; i++)
		res /= ll(i);
	return res;
}

int main()
{
	scanf("%d %d %d %d", &a, &b, &c, &l);
	ll res = C(l, 3);
	for (int i = 0; i <= l; i++) {
		int cg = a + i - b - c;
		if (cg >= 0) res -= C(min(cg, l - i), 2);
		cg = b + i - a - c;
		if (cg >= 0) res -= C(min(cg, l - i), 2);
		cg = c + i - a - b;
		if (cg >= 0) res -= C(min(cg, l - i), 2); 
	}
	printf("%I64d\n", res);
	return 0;
}