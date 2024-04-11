#include <iostream>
using namespace std;

int ans[1100500];

int main()
{
	int n;
	scanf("%d", &n);
	int N = n + 1;

	while (n > 0)
	{
		int st = 1;
		while (st <= n)
			st <<= 1;
		st >>= 1;

		int x = n - st + 1;
		for (int i = 0; i < x; i++)
		{
			ans[st + i] = st - i - 1;
			ans[st - i - 1] = st + i;
		}
		n -= 2 * x;
	}
	long long answ = 0;
	for (long long i = 0; i < N; i++)
		answ += i ^ (long long) ans[i];
	printf("%I64d\n", answ);

	for (int i = 0; i < N; i++)
		printf("%d ", ans[i] );


	return 0;
}