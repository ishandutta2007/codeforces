/* Heroes Never Die. */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
#define mp(a, b) make_pair(a, b)
#define x first
#define y second
#define read(a) scanf("%d", &a)


int n, m;
int a[1005], b[1005];

bool check(double mid) {
	for (int i = 1; i <= n; i++) {
		mid -= (mid + m) / a[i];
		if (mid < 0) return 0;
		mid -= (mid + m) / b[i];
		if (mid < 0) return 0;
	}
	return 1;
}

int main() {
	read(n); read(m);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) read(b[i]);
	double l = 0, r = 1e9 + 8;
	for (int i = 0; i < 100; i++) {
		double mid = (l + r)  / 2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	if (r < 1e9 + 7) printf("%.10lf\n", r);
	else printf("-1\n");

	return 0;
}