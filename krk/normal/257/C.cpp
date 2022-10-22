#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef pair <ld, int> di;

const int Maxn = 100005;
const ld pi = acos(-1.0l);
const ld eps = 1e-8;

int n;
int x[Maxn], y[Maxn];
di p[Maxn];
ld res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		p[i] = di(atan2(ld(y[i]), ld(x[i])), i);
	}
	sort(p, p + n);
	for (int i = 0; i < n; i++) {
		ld delt = p[(i + 1) % n].first - p[i].first;
		if (delt < 0.0) delt += 2.0 * pi;
		delt *= 180.0 / pi;
		res = max(res, delt);
	}
	printf("%.10lf\n", res < eps? 0.0: 360.0 - double(res));
	return 0;
}