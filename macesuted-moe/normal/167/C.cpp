#include <bits/stdc++.h>
using namespace std;

bool Solve(const long long a, const long long b)
{
	if (!a || !b)
		return false;
	if (!Solve(b % a, a))
		return true;
	long long k = (b / a - 1) % (a + 1);
	return k & 1 || k == a;
}

int main()
{
	int T;
	long long a, b;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld%lld", &a, &b);
		if (a > b)
			swap(a, b);
		puts(Solve(a, b) ? "First" : "Second");
	}
	return 0;
}