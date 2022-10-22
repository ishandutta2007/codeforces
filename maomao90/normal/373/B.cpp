#include <bits/stdc++.h>
using namespace std;

long long w, m, k;
long long ans;

int main() {
	scanf("%lld%lld%lld", &w, &m, &k);
	long long s = floor(log10(m)) + 1;
	while (w / s / k >= ((long long) pow(10, s) - m)) {
		ans += (long long) pow(10, s) - m;
		w -= s * k * (pow(10, s) - m);
		m = (long long) pow(10, s);
		s++;
	}
	ans += w / (s * k);
	printf("%lld\n", ans);
	return 0;
}