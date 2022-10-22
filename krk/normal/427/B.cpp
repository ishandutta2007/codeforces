#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 200005;

int n, t, c;
int a[Maxn];
int res;

int main()
{
	scanf("%d %d %d", &n, &t, &c);
	int lst = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] > t) {
			res += max(0, i - lst - c);
			lst = i;
		}
	}
	res += max(0, n - lst - c);
	printf("%d\n", res);
	return 0;
}