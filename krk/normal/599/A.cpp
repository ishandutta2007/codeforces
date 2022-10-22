#include <cstdio>
#include <algorithm>
using namespace std;

int d1, d2, d3;

int main()
{
	scanf("%d %d %d", &d1, &d2, &d3);
	printf("%d\n", min(min(d1, d2 + d3) + min(d3, d1 + d2) + min(d2, d1 + d3), min(d2, d1 + d3) + min(d3, d1 + d2) + min(d1, d2 + d3)));
	return 0;
}