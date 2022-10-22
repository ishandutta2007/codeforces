#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long double ld;

const int Maxn = 100005;
const ld eps = 1e-9;

int n, m, a, b;
ii ya[Maxn];
int yb[Maxn], l[Maxn];
ld best = 1e100;
int ba, bb;

ld Dist(ld ax, ld ay) { return sqrt(ax * ax + ay * ay); }

int main()
{
	scanf("%d %d %d %d", &n, &m, &a, &b);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ya[i].first); ya[i].second = i;
	}
	sort(ya + 1, ya + n + 1);
	for (int i = 1; i <= m; i++)
		scanf("%d", &yb[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d", &l[i]);
	for (int i = 1; i <= m; i++) {
		ld need = ld(yb[i]) / ld(b) * ld(a);
		int lef = 1, rig = n;
		int res = n + 1;
		while (lef <= rig) {
			int mid = lef + rig >> 1;
			if (need <= ya[mid].first + eps) { res = mid; rig = mid - 1; }
			else lef = mid + 1;
		}
		if (res > 1) {
			ld cand = Dist(a, ya[res - 1].first) + Dist(a - b, ya[res - 1].first - yb[i]) + l[i];
			if (cand < best) { best = cand; ba = ya[res - 1].second; bb = i; }
		}
		if (res <= n) {
			ld cand = Dist(a, ya[res].first) + Dist(a - b, ya[res].first - yb[i]) + l[i];
			if (cand < best) { best = cand; ba = ya[res].second; bb = i; }
		}
	}
	printf("%d %d\n", ba, bb);
	return 0;
}