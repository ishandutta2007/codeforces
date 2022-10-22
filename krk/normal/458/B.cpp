#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const ll Inf = 1000000000000000000ll;

int m, n;
ll a[Maxn], b[Maxn];
ll res = Inf;

int main()
{
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++)
		scanf("%I64d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%I64d", &b[i]);
	sort(a + 1, a + m + 1); sort(b + 1, b + n + 1);
	for (int i = 1; i <= m; i++)
		a[i] += a[i - 1];
	for (int j = 1; j <= n; j++)
		b[j] += b[j - 1];
	for (int i = 1; i <= m; i++) {
		ll cur = a[m - i];
		cur += b[n] <= Inf / i? b[n] * i: Inf;
		res = min(res, cur);
	}
	for (int i = 1; i <= n; i++) {
		ll cur = b[n - i];
		cur += a[m] <= Inf / i? a[m] * i: Inf;
		res = min(res, cur);
	}
	printf("%I64d\n", res);
	return 0;
}