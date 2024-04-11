#include <iostream>

using namespace std;


int getNum(int x, int k)
{
	int res = 0;
	int deg = 1;
	while(x > 0)
	{
		res += deg * (x % k);
		deg *= 10;
		x /= k;
	}
	return res;
}


int main()
{ 
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j < n; j++)
		{
			int val = i * j;
			val = getNum(val, n);
			printf("%d ", val);
		}
		printf("\n");
	}
	return 0;
}