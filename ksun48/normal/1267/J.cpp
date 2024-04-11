#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		unordered_map<int, int> mp;
		for (int i = 0; i < N; i++) {
			int c; cin >> c;
			mp[c]++;
		}
		vector<int> cnts;
		cnts.reserve(mp.size());
		for (auto it : mp) cnts.push_back(it.second);
		int maxS = *min_element(cnts.begin(), cnts.end()) + 1;
		int ans = N;
		for (int s = 1; s <= maxS; s++) {
			int cur = 0;
			for (int cnt : cnts) {
				int v = (cnt + s - 1) / s;
				if (cnt < v * (s-1)) {
					goto bad;
				}
				cur += v;
			}
			ans = min(ans, cur);
bad: ;
		}
		cout << ans << '\n';
	}

	return 0;
}