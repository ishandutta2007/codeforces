#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 2000005;

int n, a[Maxn];
ll sum[Maxn];
ll res;

bool Less(const int &a, const int &b) { return a > b; }

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n, Less);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i - 1];
	for (int i = 1; i <= n; i *= 4)
		res += sum[i];
	printf("%I64d\n", res);
	return 0;
}