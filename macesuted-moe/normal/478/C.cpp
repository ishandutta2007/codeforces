#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a, b, c;
	scanf("%lld%lld%lld", &a, &b, &c);
	printf("%lld\n", min(min(min((a + b + c) / 3, a + b), a + c), b + c));
	return 0;
}