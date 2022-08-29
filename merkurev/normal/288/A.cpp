#include <iostream>
using namespace std;


int main()
{

	int n, k;
	scanf("%d%d", &n, &k);
	if (k > n)
	{
		printf("-1");
		return 0;
	}
	if (k == 1)
	{
		if (n > 1)
		{
			printf("-1");
			return 0;
		}
		for (int i = 0; i < n; i++)
			printf("a");
		return  0;
	}
	int x = n - (k - 2);
	for (int i = 0; i < x; i++)
	{
		printf("%c", 'a' + i % 2);
	}
	for (int j = 2; j < k; j++)
		printf("%c", 'a' + j);


	return 0;
}