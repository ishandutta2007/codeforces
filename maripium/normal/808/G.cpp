#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	string t, s; cin >> t >> s;
	int n = s.size();
	vector<int> link(n);
	vector<int> nxt[26];
	for (int c = 0; c < 26; ++c) {
		nxt[c].resize(n);
	}
	int cur = link[0] = -1;
	for (int i = 1; i < n; ++i) {
		while (~cur && s[i] != s[cur + 1]) cur = link[cur];
		if (s[i] == s[cur + 1]) cur++;
		link[i] = cur;
	}
	for (int c = 0; c < 26; ++c) {
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'a' + c) {
				nxt[c][i] = i + 1;
			}
			else if (i && ~link[i - 1]) {
				nxt[c][i] = nxt[c][link[i - 1] + 1];
			}
			else {
				nxt[c][i] = (s[0] == 'a' + c);
			}
		}
	}
	int m = t.size();
	vector<vector<int>> f(m);
	for (int i = 0; i < m; ++i) {
		f[i].assign(n, -1);
	} 
	function<int(int, int)> calc = [&] (int u, int v) {
		if (u == m) return 0;
		int& ret = f[u][v];
		if (~ret) return ret;
		ret = 0;
		if (t[u] != '?') {
			int c = t[u] - 'a';
			if (nxt[c][v] == n) ret = calc(u + 1, link[v] + 1) + 1;
			else ret = calc(u + 1, nxt[c][v]);
		}
		else {
			for (int c = 0; c < 26; ++c) {
				if (nxt[c][v] == n) ret = max(ret, calc(u + 1, link[v] + 1) + 1);
				else ret = max(ret, calc(u + 1, nxt[c][v]));
			}
		}
		return ret;
	};
	cout << calc(0, 0) << '\n';
}