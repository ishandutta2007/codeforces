#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int h = 0;
	vector<pair<int, int>> as(n);
	for (int i = 0; i < n; ++i) {
		cin >> as[i].first;
		as[i].second = i+1;
		h = max(h, as[i].first);
	}

	sort(as.begin(), as.end());

	// Is there a solution using two duplicate values?
	int dup0 = -1, dup1 = -1;
	for (int i = 0; i < n; ++i) {
		if (i+1 < n && as[i+1].first == as[i].first) {
			if (dup0 == -1) dup0 = i;
			else dup1 = i;
			++i;
		}
	}
	if (dup1 != -1) {
		cout << "YES\n";
		cout << as[dup0].second << ' ' << as[dup1].second << ' ' << as[dup0 + 1].second << ' ' << as[dup1 + 1].second << '\n';
	} else {
		vector<pair<int, int>> makes(2*h+1, {-1, -1});
		for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j) {
				int t = as[i].first + as[j].first;
				if (makes[t].first != -1) {
					cout << "YES\n";
					cout << as[i].second << ' ' << as[j].second << ' ' << makes[t].first << ' ' << makes[t].second << '\n';
					return 0;
				} else {
					makes[t] = {as[i].second, as[j].second};
				}

				while(j+1 < n && as[j+1].first == as[j].first) ++j;
			}

			while(i+1 < n && as[i+1].first == as[i].first) ++i;
		}
		cout << "NO\n";
	}
}