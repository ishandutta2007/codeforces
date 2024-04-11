#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

void solve() {
	int n;
	cin >> n;

	vector<int> ord(n);
	for (int& i : ord) cin >> i;

	int res = 0;
	int cur = 1;
	int nxt = 0;
	ord[0] = n;
	for (int i = 1; i < n; ++i) {
		++nxt;
		if (ord[i] <= ord[i-1]) {
			--cur;
			if (cur == 0) {
				++res;
				cur = nxt;
				nxt = 0;
			}
		}
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int ti = 0; ti < n; ++ti) solve();
}