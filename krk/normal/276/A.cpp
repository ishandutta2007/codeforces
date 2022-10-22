#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 2000000007;

int n, k;
int res = -Inf;

int main()
{
	scanf("%d %d", &n, &k);
	while (n--) {
		int f, t; scanf("%d %d", &f, &t);
		if (t > k) res = max(res, f - (t - k));
		else res = max(res, f);
	}
	printf("%d\n", res);
	return 0;
}