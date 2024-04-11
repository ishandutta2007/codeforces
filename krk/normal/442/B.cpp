#include <cstdio>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 105;

int n;
double a[Maxn], b[Maxn];
ld nil[Maxn], one[Maxn];
ld res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lf", &a[i]);
	sort(a, a + n);
	for (int i = 0; i <= n; i++)
		for (int j = 0; i + j <= n; j++) {
			int blen = 0;
			for (int k = 0; k < i; k++)
				b[blen++] = a[k];
			for (int k = 1; k <= j; k++)
				b[blen++] = a[n - k];
			nil[0] = 1; one[0] = 0;
			for (int i = 0; i < blen; i++) {
				nil[i + 1] = nil[i] * (1.0 - b[i]);
				one[i + 1] = b[i] * nil[i] + (1.0 - b[i]) * one[i];
			}
			res = max(res, one[blen]);
		}
	printf("%.12lf\n", double(res));
	return 0;
}