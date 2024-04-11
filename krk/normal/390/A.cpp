#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxm = 105;

int n;
int x[Maxm], y[Maxm];
int a, b;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int X, Y; scanf("%d %d", &X, &Y);
		if (x[X]++ == 0) a++;
		if (y[Y]++ == 0) b++;
	}
	printf("%d\n", min(a, b));
	return 0;
}