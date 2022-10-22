#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 2000000005;
const int Maxn = 100005;

int n, l, r, ql, qr;
int w[Maxn];
int res = Inf;

int main()
{
	scanf("%d %d %d %d %d", &n, &l, &r, &ql, &qr);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]); w[i] += w[i - 1];
	}
	for (int i = 0; i <= n; i++) {
		int tot = l * w[i] + r * (w[n] - w[i]);
		if (i < n - i) tot += (n - i - i - 1) * qr;
		else if (i > n - i) tot += (i - (n - i) - 1) * ql;
		res = min(res, tot);
	}
	printf("%d\n", res);
	return 0;
}