#include <bits/stdc++.h>
using namespace std;
using ll = long long;


class DSU {
	private:
		vector<int> comp, siz;
	public:
		DSU(int n) : comp(n), siz(n, 1) {
			for (int i = 0; i < n; ++i) comp[i] = i;
		}
		int getc(int i) {
			if (comp[i] != i) comp[i] = getc(comp[i]);
			return comp[i];
		}
		bool join(int a, int b) {
			a = getc(a);
			b = getc(b);
			if (a == b) return false;

			if (siz[a] < siz[b]) swap(a, b);
			siz[a] += siz[b];
			comp[b] = a;
			return true;
		}
		int compSize(int i) { return siz[getc(i)]; }
};

int solve(int n, int k, const vector<pair<int, int>>& ed) {
	DSU dsu(n);
	int red = 0;
	for (int ind = 0; ind < k; ++ind) red += 1 - dsu.join(ed[ind].first, ed[ind].second);

	vector<int> siz;
	for (int i = 0; i < n; ++i) {
		if (dsu.getc(i) == i) siz.push_back(dsu.compSize(i));
	}
	sort(siz.rbegin(), siz.rend());

	int res = -1;
	for (int j = 0; j < min((int)siz.size(), red + 1); ++j) res += siz[j];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	// Maintain
	//	1. Sizes of connected components
	//	2. Number of redundant edges
	// If there are t redundant edges, the max degree is (sum of sizes of t + 1 largest connected components) - 1
	// n <= 10^3 so don't actually need to maintain anything

	vector<pair<int, int>> ed(m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		ed[i] = {a, b};
	}

	for (int k = 0; k < m; ++k) {
		int res = solve(n, k + 1, ed);
		cout << res << '\n';
	}
}