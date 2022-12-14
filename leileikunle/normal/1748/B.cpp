#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
using pii = pair<int, int>;
const int N = 1e6 + 10, M = N, inf = 1e9, mod = 998244353;


string s;
int n;
void solve() {

	cin >> n >> s;
	s = " " + s;
	int ans(0);
	for (int i = 1; i <= n; i++) {
		vector<int> num(10, 0);
		int cnt = 0, mx = 0;
		for (int j = i; j <= min(n, i + 100); j++) {
			int t = s[j] - '0';
			num[t]++;
			if (num[t] == 1) cnt++;
			mx = max(mx, num[t]);
			if (cnt >= mx) {
				ans++;
			}
		}
	}
	cout << ans << endl;

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