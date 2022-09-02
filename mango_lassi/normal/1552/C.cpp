#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int n, k;
		cin >> n >> k;

		vector<bool> used(2*n, 0);
		vector<pair<int, int>> ed;
		for (int i = 0; i < k; ++i) {
			int a, b;
			cin >> a >> b;
			--a; --b;
			used[a] = 1;
			used[b] = 1;
			if (a > b) swap(a, b);
			ed.emplace_back(a, b);
		}
		
		vector<int> rem;
		for (int i = 0; i < 2*n; ++i) {
			if (! used[i]) rem.push_back(i);
		}
		for (int i = 0; i < n - k; ++i) ed.emplace_back(rem[i], rem[i + n - k]);

		int res = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (ed[i].first < ed[j].first && ed[j].first < ed[i].second && ed[i].second < ed[j].second) {
					++res;
				}
			}
		}
		cout << res << '\n';
	}

}