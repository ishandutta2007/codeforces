#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());
	long long ans = 0;
	for (int i = 0; i < (n / 2); ++i) {
		int now = a[i] + a[n - i - 1];
		ans += 1LL * now * now;
	}
	cout << ans;
}