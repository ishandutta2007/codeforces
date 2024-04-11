#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define mp(a, b) make_pair
#define x first
#define y second
#define read(x) scanf("%d", &x)
#define readl(x) scanf("%lld", &x)
#define readd(x) scanf("%lf", &x)

#define N 303031

int n, m;
int a[N];


bool ok(int mid) {
	int ma = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= ma) {
			if (ma - a[i] > mid) return 0;
		}
		else {
			if (ma + m - a[i] <= mid) {

			}
			else {
				ma = a[i];
			}
		}
	}
	return 1;
}

int main() {
	read(n); read(m);
	for (int i = 1; i <= n; i++) read(a[i]);

	int l = 0, r = m - 1;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (ok(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n",l);

}