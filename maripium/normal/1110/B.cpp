#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m, k;
int a[N];

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	vector<int> buf;
	for (int i = 2; i <= n; ++i) {
		buf.push_back(a[i] - a[i - 1] - 1);
	}
	sort(buf.begin(), buf.end());
	long long ans = (long long) n;
	for (int i = 0; i < n - k; ++i) {
		ans += buf[i];
	}
	printf("%lld\n", ans);
}