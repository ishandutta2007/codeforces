#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using pii = pair<int, int>;
#define x first
#define y second
const int N = 2e5 + 10, inf = 1e6;
int a[N], n;

mt19937 rnd(time(0));

void solve() {


	cin >> n;

	map<int, int> cnt;
	for (int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++;

	for (auto [x, y] : cnt) if (y >= n / 2) return void(cout << -1 << endl);

	auto check = [&](int k) -> bool{

		map<int, int> mp;
		for (int i = 1; i <= n; i++) {
			int t = (a[i] + inf * k) % k;
			mp[t]++;
			if (mp[t] >= n / 2) return true;
		}
		return false;

	};

	int t(1000), ans(1);
	while (t--) {

		int q = rnd() % n + 1, w = rnd() % n + 1;
		int res = abs(a[q] - a[w]);
		for (int i = 1; i * i <= res; i++) {
			if (res % i) continue;
			if (check(i)) ans = max(ans, i);
			if (check(res / i)) ans = max(ans, res / i);
		}
	}
	cout << ans << endl;

}
signed main() {
	cin.tie(0) -> ios::sync_with_stdio(0);
	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}



}