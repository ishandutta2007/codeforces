#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e9 + 7;

void solve() {
	string str;
	cin >> str;

	vector<int> sta, cou(10, 0);
	for (auto c : str) {
		int v = (c - '0');
		while(! sta.empty() && sta.back() > v) {
			++cou[min(9, sta.back() + 1)];
			sta.pop_back();
		}
		sta.push_back(v);
	}

	int j = 0;
	for (int v : sta) {
		while(j <= v) {
			if (cou[j] == 0) ++j;
			else {
				--cou[j];
				cout << j;
			}
		}
		cout << v;
	}
	while(j <= 9) {
		if (cou[j] == 0) ++j;
		else {
			--cou[j];
			cout << j;
		}
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}