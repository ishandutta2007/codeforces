#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();
		vector<int> segs;
		for (int i = 0; i < n;) {
			int j = i;
			while (j < n && s[j] == '0') j++;
			if (j == n) break;
			i = j;
			while (j < n && s[j] == '1') j++;
			segs.push_back(j - i);
			i = j;
		}
		sort(segs.rbegin(), segs.rend());
		int ans = 0;
		for (int i = 0; i < segs.size(); i += 2) ans += segs[i];
		cout << ans << '\n';
	}
}