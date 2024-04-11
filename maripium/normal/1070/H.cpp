#include <bits/stdc++.h>
using namespace std;

int n, q;
map<string, vector<string>> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		string s; cin >> s;
		int sz = s.size();
		map<string,int> seen;
		for (int l = 0; l < sz; ++l) {
			string cur = "";
			for (int r = l; r < min(l + 8, sz); ++r) {
				cur += s[r];
				if (seen.count(cur)) continue;
				seen[cur] = 1;
				mp[cur].push_back(s);
			}
		}
	}
	cin >> q;
	while (q--) {
		string s; cin >> s;
		if (mp.count(s)) {
			vector<string> se = mp[s];
			cout << se.size() << ' ' << *se.begin() << '\n';
		}
		else cout << 0 << ' ' << '-' << '\n';
	}
}