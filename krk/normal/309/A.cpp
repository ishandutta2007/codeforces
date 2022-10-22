#include <cstdio>
#include <cmath>
using namespace std;

typedef long double ld;

const int Maxn = 1000005;
const ld eps = 1e-9l;

int n, l, t;
int a[Maxn];
ld res1, res2;

int main()
{
	scanf("%d %d %d", &n, &l, &t);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		ld quot = floor(t / (l / 2.0l));
		ld rem = t - (l / 2.0l) * quot;
		res1 += ld(n - 1) * (quot + 1);
		int lef = 1, rig = n - 1, res = n;
		while (lef <= rig) {
			int mid = lef + rig >> 1;
			int d = (a[i] + l - a[(i - mid + n) % n]) % l;
			if (d / 2.0l > rem + eps) { res = mid; rig = mid - 1; }
			else lef = mid + 1;
		}
		res1 -= n - res;
	}
	printf("%.10lf\n", double(0.25 * res1));
	return 0;
}