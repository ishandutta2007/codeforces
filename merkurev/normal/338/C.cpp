#include <iostream>
#include <algorithm>
using namespace std;


long long a[9];


long long numDiv[9];




long long remaind[9];
int n;

long long ans = 1, answer = 1e15;

void generate(int i, bool minusOne = true)
{
	if (i == n)
	{
		answer = min(answer, ans - (minusOne ? 1 : 0) );
		return;
	}

	long long cur = a[i];

	generate(i + 1, i == 0 ? true : false);

	for (int j = 0; j < i; j++)
	{
		if (remaind[j] != 0 && remaind[j] % cur == 0)
		{
			remaind[j] /= cur;
			ans -= numDiv[i];

			generate(i + 1, minusOne);
			
			ans += numDiv[i];
			remaind[j] *= cur;
		}
	}
}

int main()
{

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i] );

	sort(a, a + n);
	reverse(a, a + n);

	for (int i = 0; i < n; i++)
	{
		long long cur = a[i];
		int curans = 0;

		for (long long j = 2; j * j <= cur; j++)
		{
			while (cur != 0 && cur % j == 0)
			{
				cur /= j;
				curans ++;
			}
		}
		if (cur != 1)
			curans++;

		numDiv[i] = curans;
		ans += curans + (curans == 1 ? 0 : 1);
	}

	for (int i = 0; i < n; i++)
		remaind[i] = a[i];
	generate(0);



	printf("%I64d", answer);

	return 0;
}