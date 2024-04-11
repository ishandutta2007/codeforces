#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1e9 + 7;

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

void solve() {
	int n, m;
	cin >> n >> m;
	DSU dsu(m+1);

	vector<int> res;
	for (int i = 0; i < n; ++i) {
		int k, a, b;
		cin >> k;
		if (k == 1) {
			cin >> a;
			b = 0;
		} else {
			cin >> a >> b;
		}
		if (dsu.join(a, b)) res.push_back(i + 1);
	}

	ll cou = 1;
	for (auto v : res) {
		cou = (cou * 2) % MOD;
	}
	
	cout << cou << ' ' << res.size() << '\n';
	for (auto v : res) cout << v << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}