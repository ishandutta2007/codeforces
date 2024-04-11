#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;
const int Inf = 1000000000;

int n;
int a[Maxn];
int r1, c1, r2, c2;
int res = Inf;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
	if (r1 <= r2) {
		int mn = c1;
		for (int i = r1 + 1; i <= r2; i++) mn = min(mn, a[i] + 1);
		int cmin = mn;
		for (int i = r1; i >= 1; i--) {
			cmin = min(cmin, a[i] + 1);
			res = min(res, r1 - i + r2 - i + abs(cmin - c2));
		}
		cmin = mn;
		for (int i = r2; i <= n; i++) {
			cmin = min(cmin, a[i] + 1);
			res = min(res, i - r1 + i - r2 + abs(cmin - c2));
		}
	} else {
		int mn = c1;
		for (int i = r1 - 1; i >= r2; i--) mn = min(mn, a[i] + 1);
		int cmin = mn;
		for (int i = r1; i <= n; i++) {
			cmin = min(cmin, a[i] + 1);
			res = min(res, i - r1 + i - r2 + abs(cmin - c2));
		}
		cmin = mn;
		for (int i = r2; i >= 1; i--) {
			cmin = min(cmin, a[i] + 1);
			res = min(res, r2 - i + r1 - i + abs(cmin - c2));
		}
	}
	printf("%d\n", res);
	return 0;
}