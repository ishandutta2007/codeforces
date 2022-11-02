# include <iostream>
# include <cstdio>
using namespace std;

int n, l, v1, v2, k;

const long double eps = 1e-8;

bool calc(long double limit) {
	long double cur = l;
	for(int i = 0; i < n; i += k) {
		long double t = (cur - limit * v1) / (v2 - v1);
		if(t > limit + eps) return false;
		if(i + k < n) {
			t += (v2 - v1) * t / (v2 + v1);
			limit -= t;
			if(limit < -eps) return false;
			cur -= t * v1;
		}
	}
	return true;
}

int main() {
	scanf("%d%d%d%d%d", &n, &l, &v1, &v2, &k);
	long double L = 0, R = l * 1. / v1;
	while(R - L > eps) {
		long double mid = (L + R) / 2;
		calc(mid) ? R = mid : L = mid;
	}
	printf("%.8lf\n", (double)R);
}