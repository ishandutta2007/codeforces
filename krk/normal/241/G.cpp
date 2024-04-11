#include <cstdio>
using namespace std;

int main()
{
	printf("500\n");
	printf("0 1000000\n");
	for (int i = 2; i <= 499; i++)
		printf("%d %d\n", (i - 1) * 2000, 500 - i);
	printf("1000000 1000000\n");
	return 0;
}