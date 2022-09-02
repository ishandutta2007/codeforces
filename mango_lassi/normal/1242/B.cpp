#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

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


const int N = 1e5;
vector<int> conns[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int j = 0; j < m; ++j) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}

	// If every node has at most n/2 - 10 out-edges, possible with zero.
	// Otherwise, loop all with n/2 - 10 out-edges, connect everything they have edges to.
	// All nodes with at most n/2 - 10 out-edges are connected to eachother

	int res = n-1;
	int pr = -1;
	DSU dsu(n);
	for (int i = 0; i < n; ++i) {
		if ((int)conns[i].size() >= n/2 - 10) {
			sort(conns[i].begin(), conns[i].end());
			int j = 0;
			for (int x = 0; x < n; ++x) {
				if (x == i) continue;
				while (j < conns[i].size() && conns[i][j] < x) ++j;
				if (j < conns[i].size() && conns[i][j] == x) continue;
				else res -= dsu.join(i, x);
			}
		} else {
			if (pr != -1) res -= dsu.join(pr, i);
			pr = i;
		}
	}
	cout << res << '\n';
}