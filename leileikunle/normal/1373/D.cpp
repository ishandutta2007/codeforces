#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using pii = pair<int, int>;
const int N = 1e6 + 10, mod = 1e9 + 7, maxn = 10000010;;
#define all(a) a.begin(),a.end()

void solve() {

	int n, sum(0);
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i % 2 == 0) sum += a[i];
	}

	int res1(0), res2(0), mx(0);
	for (int i = 0; i < n; i += 2) {
		if (i + 1 < n) {
			res1 += a[i + 1] - a[i];
			mx = max(mx, res1);
			if (res1 < 0) res1 = 0;
		}
		if (i > 0) {
			res2 += a[i - 1] - a[i];
			mx = max(mx, res2);
			if (res2 < 0) res2 = 0;
		}
	}

	cout << sum + mx << endl;

}
signed main() {
	cin.tie(0) -> ios::sync_with_stdio(false);
	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}
}