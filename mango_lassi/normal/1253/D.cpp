#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

class DSU {
	private:
		vector<int> comp, siz, mins;
	public:
		DSU(int n) : comp(n), siz(n, 1) {
			for (int i = 0; i < n; ++i) comp[i] = i;
			mins = comp;
		}
		int getc(int i) {
			if (comp[i] != i) comp[i] = getc(comp[i]);
			return comp[i];
		}
		bool rep(int i) {
			int j = getc(i);
			return mins[j] == i;
		}
		bool join(int a, int b) {
			a = getc(a);
			b = getc(b);
			if (a == b) return false;

			if (siz[a] < siz[b]) swap(a, b);
			siz[a] += siz[b];
			comp[b] = a;
			mins[a] = min(mins[a], mins[b]);
			return true;
		}
		int compSize(int i) { return siz[getc(i)]; }
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	DSU dsu(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		dsu.join(a-1, b-1);
	}

	// do DSU, merge overlapping components
	int res = 0;
	vector<int> sta;
	for (int i = 0; i < n; ++i) {
		if (! dsu.rep(i)) {
			while(true) {
				bool add = dsu.join(sta.back(), i);
				if (add) {
					++res;
					sta.pop_back();
				} else break;
			}
		} else {
			sta.push_back(i);
		}
	}
	cout << res << '\n';
}