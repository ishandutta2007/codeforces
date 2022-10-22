#include <cstdio>
#include <string>
using namespace std;

const int segs[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int Get(int x)
{
	int res = 0;
	while (x) {
		res += segs[x % 10];
		x /= 10;
	}
	return res;
}

int main()
{
	int a, b; scanf("%d %d", &a, &b);
	int res = 0;
	for (int i = a; i <= b; i++)
		res += Get(i);
	printf("%d\n", res);
	return 0;
}