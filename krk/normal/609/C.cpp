#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];
int tot;
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); tot += a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		int my = tot / (n - i);
		if (a[i] > my) res += a[i] - my;
		tot -= my;
	}
	printf("%d\n", res);
	return 0;
}