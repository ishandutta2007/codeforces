#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

const ld Inf = 10e30;
const int Maxn = 100005;

int n;
int X, Y;
int x[Maxn], y[Maxn];
ld mn = Inf, mx = -Inf;

ll Dot(ll ax, ll ay, ll bx, ll by) { return ax * bx + ay * by; }

ll Cross(ll ax, ll ay, ll bx, ll by) { return ax * by - ay * bx; }

ld Len(ll ax, ll ay) { return sqrt(ld(ax) * ax + ld(ay) * ay); }

int main()
{
	scanf("%d %d %d", &n, &X, &Y);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		ld dist = sqrt(ld(x[i] - X) * ld(x[i] - X) + ld(y[i] - Y) * ld(y[i] - Y));
		mx = max(mx, dist);
		mn = min(mn, dist);
	}
	for (int i = 0; i < n; i++) {
		int ni = (i + 1) % n;
		if (Dot(x[i] - x[ni], y[i] - y[ni], X - x[ni], Y - y[ni]) >= 0 &&
			Dot(x[ni] - x[i], y[ni] - y[i], X - x[i], Y - y[i]) >= 0) {
			ll ax = x[i] - x[ni], ay = y[i] - y[ni];
			ll bx = X - x[ni], by = Y - y[ni];
			ll S = abs(Cross(ax, ay, bx, by));
			ld h = S / Len(ax, ay);
			mn = min(mn, h);
		}
	}
	printf("%.15lf\n", double(acos(-1.0l) * (mx * mx - mn * mn)));
	return 0;
}