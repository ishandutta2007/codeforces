#include <iostream>
#include <algorithm>
using namespace std;


int a[1005];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	int k = n;
	n = n * 2 - 1;

	int minAbs = 1005;

	int cntNeg = 0;
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i] );
			minAbs = min(minAbs, abs(a[i] ) );
		if (a[i] < 0)
		{
			cntNeg++;
		}
		sum += abs(a[i] );
	}
	if (cntNeg % 2 == 1 && k % 2 == 0)
	{
		sum -= 2 * minAbs;
	}
	printf("%d\n", sum);




	return 0;
}