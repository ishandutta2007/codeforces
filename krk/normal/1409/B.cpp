#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int a, b, x, y, n;

ll Solve(int a, int b, int x, int y, int n)
{
	int tk = min(a - x, n);
	a -= tk; n -= tk;
	tk = min(b - y, n);
	b -= tk; n -= tk;
	return ll(a) * b;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d %d %d", &a, &b, &x, &y, &n);
		printf("%I64d\n", min(Solve(a, b, x, y, n), Solve(b, a, y, x, n)));
	}
    return 0;
}