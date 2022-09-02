#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void buildDP(int i, int p, vector<vector<int>>& even_clears, vector<vector<int>>& odd_clears, const vector<vector<int>>& g) {
	vector<int> even, odd, both;
	for (int t : g[i]) {
		if (t == p) continue;
		buildDP(t, i, even_clears, odd_clears, g);
		bool ev = !even_clears[t].empty();
		bool od = !odd_clears[t].empty();
		if (ev && od) both.push_back(t);
		else if (ev) even.push_back(t);
		else if (od) odd.push_back(t);
		else return; // Impossible
	}
	
	for (int d = 0; d <= 1; ++d) {
		if (d == 0) even.push_back(p);
		else odd.push_back(p);

		int deg = g[i].size();
		int par = deg & 1;
		
		vector<int> tmp0 = (par ? odd : even), tmp1 = (par ? even : odd), tmp2 = both;
		bool can = 1;
		can &= (tmp0.size() <= tmp1.size() + tmp2.size() + 1);
		can &= (tmp1.size() <= tmp0.size() + tmp2.size());	
		
		if (can) {
			vector<int>& ord = (d ? odd_clears[i] : even_clears[i]);
			while(tmp0.size() + tmp2.size()) {
				if (tmp0.empty()) {
					ord.push_back(tmp2.back());
					tmp2.pop_back();
				} else {
					ord.push_back(tmp0.back());
					tmp0.pop_back();
				}
				swap(tmp0, tmp1);
			}
		}

		if (d == 0) even.pop_back();
		else odd.pop_back();
	}

	/*
	cerr << "BuildDP(" << i << ' ' << p << "): {";
	for (int j : even_clears[i]) cerr << j << ' '; cerr << "}, {";
	for (int j : odd_clears[i]) cerr << j << ' '; cerr << "}\n";
	*/
}

void recClear(int i, int p, int d, const vector<vector<int>>& even_clears, const vector<vector<int>>& odd_clears, const vector<vector<int>>& g) {
	const vector<int>& ord = (d ? odd_clears[i] : even_clears[i]);
	int deg = g[i].size();
	for (int t : ord) {
		if (t == p) {
			cout << i + 1 << ' ' << t + 1 << '\n';
		} else {
			recClear(t, i, deg & 1, even_clears, odd_clears, g);
		}
		--deg;
	}
}

void solve() {
	int n;
	cin >> n;

	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	int s = 0;
	for (int i = 1; i < n; ++i) {
		if (g[i].size() == 1) s = i;
	}
	int t = g[s][0];
	
	vector<vector<int>> even_clears(n), odd_clears(n);
	buildDP(t, s, even_clears, odd_clears, g);

	if (odd_clears[t].empty()) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		recClear(t, s, 1, even_clears, odd_clears, g);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}