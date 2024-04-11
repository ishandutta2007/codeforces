#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int a[Maxn], b[Maxn];
ll res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		if (2 * a[i] >= b[i] && b[i] != 1) {
			ll prt1 = b[i] / 2;
			ll prt2 = b[i] - prt1;
			res += prt1 * prt2;
		} else res--;
	}
	printf("%I64d\n", res);
	return 0;
}