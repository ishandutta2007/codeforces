#include <cstdio>
#include <algorithm>
using namespace std;

int n, sum;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		sum += a;
	}
	printf("%d\n", n - (sum % n != 0));
	return 0;
}