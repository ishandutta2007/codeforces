#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10, V = 1000000;
bitset<N> dp;
int n, a[20];
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		dp.reset();
		dp[V] = 1;
		for(int j = 1; j <= n; j++) {
			if(i == j) continue;
			int x = abs(a[j]);
			dp |= dp << x;
			dp |= dp >> x;
		}
		if(dp[V + a[i]] || dp[V - a[i]]) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
	return;
}

int main() {
	int T;
	for(cin >> T;T-- ; ) {
		solve();
	}
    return 0;
}