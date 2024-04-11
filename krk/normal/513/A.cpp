#include <cstdio>
using namespace std;

int n1, n2, k1, k2;

int main()
{
	scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
	printf("%s\n", n1 <= n2? "Second": "First");
	return 0;
}