#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

typedef long double ld;

int a, b;

int main()
{
	scanf("%d %d", &a, &b);
	if (a < b) printf("-1\n");
	else if (a == b) printf("%d\n", b);
	else {
		int n = (a / b + 1) / 2;
		ld res = ld(a + b) / (2 * n);
		n = (a / b - 1) / 2;
		if (n > 0) res = min(res, ld(a - b) / (2 * n));
		cout << fixed << setprecision(10) << res << endl;
	}
	return 0;
}