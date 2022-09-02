#include <iostream>
#include <vector>
#include <algorithm>
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

const int N = 1 << 18;
vector<int> ind[N];
int cou[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	ll res = 0;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		++cou[v];
		res -= v;
	}
	++cou[0];

	DSU dsu(N+1);
	for (int m = N-1; m >= 0; --m) {
		for (int x = m; x; x = (x-1) & m) {
			int y = m^x;
			if (cou[x] == 0 || cou[y] == 0) continue;
			if (dsu.getc(x) == dsu.getc(y)) continue;

			res += (ll)(cou[x] + cou[y] - 1) * (x + y);
			dsu.join(x, y);
			cou[x] = 1;
			cou[y] = 1;
		}
	}

	cout << res << '\n';
}