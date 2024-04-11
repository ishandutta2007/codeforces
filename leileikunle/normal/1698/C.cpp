#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
using pii = pair<int, int>;
const int N = 1e6 + 10, M = N, inf = 1e18, mod = 998244353;

void solve() {

	int n, sum(0), cnt1(0), cnt2(0), cnt0(0);
	cin >> n;
	vector<int> a(n);
	set<int> s;
	for (auto &i : a) {
		cin >> i, s.insert(i);
		if (!i) cnt0++;
		sum += i;
	}
	sort(all(a));
	if (cnt0 >= n - 1) return void(cout << "YES" << endl);
	if (n <= 10) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					if (!s.count(a[i] + a[j] + a[k])) return void(cout << "NO" << endl);
				}
			}
		}
		return void(cout << "YES" << endl);
	}
	for (auto i : a) {
		if (i > 0) cnt1++;
		if (i < 0) cnt2++;
	}
	if (sum or cnt1 > 1 or cnt2 > 1)return void(cout << "NO" << endl);
	return void(cout << "YES" << endl);
}
signed main() {
	cin.tie(0) -> ios::sync_with_stdio(false);
	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}