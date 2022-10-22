#include <cstdio>
using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	if (n % 2 == 0) {
		printf("white\n");
		printf("1 2\n");
	} else printf("black\n");
	return 0;
}