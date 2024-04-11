#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
int n, k, x[N], y[N], z[N];

int oper(int x, int y, int z) {
	if(x <= y) return x <= z && z <= y;
	return x <= z || z <= y;
}

void solve() {
	cin >> n >> k;
	for(int i = 1; i <= 2 * n; i++) z[i] = 0;
	for(int i = 1; i <= k; i++) {
		cin >> x[i] >> y[i];
		z[x[i]] = z[y[i]] = 1;
	}
	int ans = (n - k) * (n - k - 1) / 2;
	for(int i = 1; i <= k; i++) {
		for(int j = i + 1; j <= k; j++) {
			if(oper(x[i], y[i], x[j]) == oper(y[i], x[i], y[j])) {
				ans++;
			}
		}
	}
	for(int i = 1; i <= k; i++) {
		int sze = 0;
		for(int j = 1; j <= 2 * n; j++) {
			if(!z[j] && oper(x[i], y[i], j) == 1) {
				sze++;
			}
		}
		ans += min(sze, 2 * (n - k) - sze);
	}
	cout << ans << endl;
	return;
}

int main() {
	int T;
	for(cin >> T;T-- ; ) {
		solve();
	}
    return 0;
}