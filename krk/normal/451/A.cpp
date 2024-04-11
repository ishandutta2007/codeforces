#include <cstdio>
#include <algorithm>
using namespace std;

int a, b;

int main()
{
	scanf("%d %d", &a, &b);
	printf("%s\n", min(a, b) % 2? "Akshat": "Malvika");
	return 0;
}