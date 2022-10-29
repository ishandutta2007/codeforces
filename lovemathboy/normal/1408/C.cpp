#include <bits/stdc++.h>
using namespace std;

int tc;
int n, l;

int main() {
	scanf("%d", &tc);
	for (int cas = 1; cas <= tc; cas++) {
		scanf("%d %d", &n, &l);
		vector<int> a;
		a.resize(n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		long double s1 = 1.0, p1 = 0.0, s2 = 1.0, p2 = (long double)l;
		long double ans = 0.0;
		int f1 = 0, f2 = n-1;
		while (f2 >= f1) {
			long double t1 = (a[f1] - p1)/s1;
			long double t2 = (p2 - a[f2])/s2;
			if (t1 < t2) {
				p1 += t1 * s1;
				s1++; f1++;
				p2 -= t1 * s2;
				ans += t1;
			}
			else {
				p2 -= t2 * s2;
				s2++; f2--;
				p1 += t2 * s1;
				ans += t2;
			}
		}
		printf("%.9Lf\n", ans + (p2 - p1) / (s1 + s2));
	}
}