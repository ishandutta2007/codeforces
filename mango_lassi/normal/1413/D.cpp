#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> evs(2*n);
	for (int i = 0; i < 2*n; ++i) {
		char c;
		cin >> c;
		if (c == '+') evs[i] = -1;
		else cin >> evs[i];
	}

	bool fail = 0;
	vector<int> sta, ans;
	for (int i = 2*n-1; i >= 0; --i) {
		if (evs[i] >= 0) {
			if (! sta.empty() && sta.back() <= evs[i]) fail = 1;
			sta.push_back(evs[i]);
		} else {
			if (sta.empty()) fail = 1;
			else {
				ans.push_back(sta.back());
				sta.pop_back();
			}
		}
	}

	if (fail) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for (int i = n-1; i >= 0; --i) cout << ans[i] << ' '; cout << '\n';
	}
}