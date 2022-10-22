#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

typedef long double ld;

int m, n;
ld res;

ld toPow(ld a, int p)
{
	ld res = 1.0l;
	while (p) {
		if (p & 1) res *= a;
		p >>= 1; a *= a;
	}
	return res;
}

int main()
{
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++) {
		ld fail = toPow(ld(i - 1) / i, n);
		res = (1.0l - fail) * i + fail * res;
	}
	cout << fixed << setprecision(12) << res << endl;
	return 0;
}