#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	map<long long,long long> f;
	f[(long long) 1e18] = 0;
	for (int i = 1; i <= n; ++i) {
		long long md;
		scanf("%lld", &md);
		for (auto it = f.lower_bound(md); it != f.end(); f.erase(it++)) {
			f[md - 1] = max(f[md - 1], it->second + (it->first - it->first % md - md) * (i - 1));
			f[it->first % md] = max(f[it->first % md], it->second + (it->first - it->first % md) * (i - 1));
		}
	}
	long long ans = 0;
	for (auto it : f) {
		ans = max(ans, it.first * n + it.second);
	}
	printf("%lld\n", ans);
}