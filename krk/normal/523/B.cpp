#include <cstdio>
#include <cmath>
using namespace std;

typedef long double ld;

const int Maxn = 200005;

int n, T;
double c;
int a[Maxn];
ld res1, res2;
int m;

int main()
{
	scanf("%d %d %lf", &n, &T, &c);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= T; i++) {
		res1 += a[i]; res2 = (res2 + ld(a[i]) / T) / c;
	}
	int cur = T;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int p; scanf("%d", &p);
		while (cur < p) {
			cur++;
			res1 += a[cur] - a[cur - T]; res2 = (res2 + ld(a[cur]) / T) / c;
		}
		ld rl = res1 / T;
		printf("%.6lf %.6lf %.6lf\n", double(rl), double(res2), double(fabs(rl - res2) / rl)); 
	}
	return 0;
}