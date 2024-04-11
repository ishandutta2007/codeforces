#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;

int n, m, a, b;
int res = Inf;

int main()
{
	scanf("%d %d %d %d", &n, &m, &a, &b);
	for (int i = 0; i <= n; i++) {
		int lft = max(0, n - m * i);
		res = min(res, a * lft + i * b);
	}
	printf("%d\n", res);
	return 0;
}