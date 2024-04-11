#include <bits/stdc++.h>
using namespace std;

#define double long double
const double eps = 1e-9;
const double inf = 2e9;

int n;
double m;
double a[1005], b[1005];

bool ok(double mid) {
	double sum = mid + m;
	for (int i = 1; i < n; ++i) {
		double need = sum / a[i];
		if (need > mid) return 0;
		sum -= need, mid -= need;
		need = sum / b[i + 1];
		if (need > mid) return 0;
		sum -= need, mid -= need;
	}
	double need = sum / a[n];
	if (need > mid) return 0;
	sum -= need, mid -= need;
	need = sum / b[1];
	if (need > mid) return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	
	double l = 0, r = inf;
	
	while (l + eps < r) {
		double mid = (l + r) / 2;
		if (ok(mid)) r = mid;
		else l = mid;
	}
	if (inf - l < eps) cout << -1;
	else cout << fixed << setprecision(6) << l;
}