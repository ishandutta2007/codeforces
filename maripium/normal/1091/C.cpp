#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> dvs;
	for (int i = 1; i * i <= n; ++i) if (n % i == 0) {
		dvs.push_back(i);
		if (i < (n / i)) dvs.push_back((n / i));
	}
	vector<long long> ans;
	for (int d : dvs) {
		int nd = n / d;
		ans.push_back(1LL * d * (2 + n - nd) / 2);
	}
	sort(ans.begin(), ans.end());
	ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
	for (auto x : ans) printf("%lld ", x);
}