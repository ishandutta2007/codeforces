#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	// While minimum is first or last, remove it
	// k >= length of remaining array work

	vector<pair<int, int>> pos(n);
	for (int i = 0; i < n; ++i) {
		cin >> pos[i].first;
		pos[i].second = i;
	}
	sort(pos.begin(), pos.end());

	bool eq = 0;
	for (int i = 0; i + 1 < n; ++i) {
		if (pos[i].first == pos[i+1].first) eq = 1;
	}

	int a = 0;
	int b = n-1;
	for (int i = 0; i < n; ++i) {
		if (pos[i].first > i + 1) {
			--a;
			break;
		}

		if ((i + 1) < n && pos[i].first == pos[i+1].first) break;
		if (pos[i].second == a) ++a;
		else if (pos[i].second == b) --b;
		else break;
	}

	cout << (!eq);
	for (int i = 1; i < b - a; ++i) cout << '0';
	for (int j = max(1, b - a); j < n; ++j) cout << '1';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int ti = 0; ti < n; ++ti) solve();
}