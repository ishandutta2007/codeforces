#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int Maxn = 100005;

int T;
int n, m;
int a[Maxn];
ld sum[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			sum[i] = 1;
		}
		for (int i = 0; i < m; i++) {
			int r; double p;
			scanf("%d %lf", &r, &p);
			sum[r] *= (1.0l - ld(p));
		}
		int pnt = n;
		while (a[pnt] == pnt && pnt > 0) {
			sum[pnt - 1] *= sum[pnt];
			pnt--;
		}
		double res = pnt == 0? 1.0: 1.0l - sum[pnt];
		printf("%.6f\n", res + double(1e-9));
	}
    return 0;
}