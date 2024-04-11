#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
long long T;
long long a[N], b[N];

bool check(int mid) {
	long long t = 0;
	int num = 0;
	int last = (mid - 1) / m * m;
	for (int i = 1; i <= n; ++i) {
		if (a[i] > b[mid]) continue;
		t += a[i];
		if (++num <= last) t += a[i];
		if (num == mid) break;
	}
	return t <= T;
}

void solve() {
	cin >> n >> m >> T;
	for (int i = 1; i <= n; ++i) cin >> a[i], b[i] = a[i];
	sort(b + 1, b + 1 + n);
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << ' ' << (l == 0 ? 1 : b[l]) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	int tt; cin >> tt;
	while (tt--) {
		solve();
	}
}