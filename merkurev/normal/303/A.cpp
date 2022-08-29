#include <iostream>
using namespace std;



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);

	if (n % 2 == 0)
	{
		printf("-1");
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", (i + i) % n);
	}



	return 0;
}