#include <bits/stdc++.h>
using namespace std;

int k, n, s, p;

int main()
{
	scanf("%d %d %d %d", &k, &n, &s, &p);
	int one = n / s + bool(n % s > 0);
	int all = one * k;
	int nd = all / p + bool(all % p > 0);
	printf("%d\n", nd);
	return 0;
}