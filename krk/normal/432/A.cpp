#include <cstdio>
using namespace std;

int n;
int k;
int res;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		res += a + k <= 5;
	}
	printf("%d\n", res / 3);
	return 0;
}