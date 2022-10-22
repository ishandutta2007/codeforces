#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 300005;

int n;
int a[Maxn];
ll sum;
ll res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); sum += a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		res += sum + a[i]; sum -= a[i];
	}
	res -= a[n - 1];
	printf("%I64d\n", res);
	return 0;
}