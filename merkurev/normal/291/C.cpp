#include <iostream>
#include <algorithm>
using namespace std;


long long A[100500];

int main()
{


	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		long long a, b, c, d;
		scanf("%I64d.%I64d.%I64d.%I64d", &a, &b, &c, &d);
		A[i] = ( ( ( ( ( (a << 8) | b) << 8) | c) << 8) | d);
	}
	sort(A, A + n);


	long long cur = (1LL << 32) - 1;
	long long ans = -1;
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < n; j++)
			A[j] &= cur;
		n = unique(A, A + n) - A;
		if (n == k)
			ans = cur;

		cur ^= (1LL << i);
	}
	if (ans == -1)
	{
		printf("-1");
		return  0;
	}
	long long x[4];
	for (int i = 0; i < 4; i++)
	{
		x[i] = (ans & 255);
		ans >>= 8;
	}
	printf("%I64d.%I64d.%I64d.%I64d", x[3], x[2], x[1], x[0] );


	return 0;
}