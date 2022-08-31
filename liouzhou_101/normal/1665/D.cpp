#include <bits/stdc++.h>

using namespace std;

int oj = 1;
int X = 123456;

int query(int a, int b)
{
	printf("? %d %d\n", a, b);
	fflush(stdout);
	if (oj)
	{
		int c;
		scanf("%d", &c);
		return c;
	}
	else
	{
		return gcd(a + X, b + X);
	}
}

bool answer(int x)
{
	printf("! %d\n", x);
	fflush(stdout);
	return oj ? true : X == x;
}

void solve()
{
	int res = 0;
	for (int k = 0; k < 30; ++k)
	{
		int a = (1 << k) - res;
		int b = (1 << (k + 1)) + a;
		int c = query(a, b);
		if ((c >> k & 1) == 0 && c > 1 << k)
		{
			res |= 1 << k;
		}
	}
	assert(answer(res));
}

int main()
{
	int tests;
	if (oj)
		cin >> tests;
	else
		tests = 1;
	while (tests--) solve();
	return 0;
}