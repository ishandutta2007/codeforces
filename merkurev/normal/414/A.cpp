#include <iostream>
using namespace std;



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
        int n, k;
	scanf("%d%d", &n, &k);
	int x = n / 2;
	if (k < x)
	{
		printf("-1");
		return 0;
	}
	if (n < 2)
	{
		if (k == 0)
			printf("1");
		else
			printf("-1");
		return 0;
	}
	
	int nk = k - x + 1;
	printf("%d %d ", nk, 2 * nk);
	int y = 2 * nk + 1;
	for (int i = 2; i < n; i++)
	{
		printf("%d ", y++);
	}



	return 0;
}