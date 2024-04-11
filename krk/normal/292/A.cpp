#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int t, q;
int res;

int main()
{
	scanf("%d", &n);
	while (n--) {
		int ti, ci; scanf("%d %d", &ti, &ci);
		q = max(q - (ti - t), 0); t = ti;
		q += ci;
		res = max(res, q);
	}
	printf("%d %d\n", t + q, res);
	return 0;
}