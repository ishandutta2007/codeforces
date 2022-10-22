#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<pair<int, int>> events;
		for (int i = 1; i <= n; ++i) {
			int l, r;
			cin >> l >> r;
			events.emplace_back(l, -i);
			events.emplace_back(r, i);
		}
		sort(events.begin(), events.end());
		set<int> scanner;
		vector<int> cnt(n + 1);
		int ans = 0;
		for (const auto& event : events) {
			int i = abs(event.second);
			if (event.second < 0) {
				if (scanner.empty()) --cnt[i];
				scanner.insert(i);
			} else {
				scanner.erase(i);
				if (scanner.empty()) --cnt[i];
			}
			if (scanner.empty()) ++ans;
			if (int(scanner.size()) == 1) ++cnt[*scanner.cbegin()];
		}
		cout << ans + *max_element(next(cnt.cbegin()), cnt.cend()) << "\n";
	}
}