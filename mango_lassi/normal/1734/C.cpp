#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18 + 7;

void solve() {
	int n;
	cin >> n;

	string str;
	cin >> str;

	vector<int> state(n + 1);
	for (int i = 1; i <= n; ++i) state[i] = (str[i - 1] == '1' ? 1 : -1);
	
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; j += i) {
			if (state[j] == 1) break;
			else if (state[j] == -1) {
				res += i;
				state[j] = 0;
			}
		}
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}