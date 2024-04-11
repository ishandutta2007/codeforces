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

const int N = 2 * (int)1e5;
const int C = 26;
int cou[N][C+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int ti = 0; ti < tc; ++ti) {
		int n, k;
		cin >> n >> k;

		string str;
		cin >> str;

		// Just DSU parts which must be equal, then convert these components individually
		DSU dsu(n);
		for (int i = 0; i < n; ++i) {
			if (i+k < n) dsu.join(i, i + k);
			dsu.join(i, n-1-i);
		}
		for (int i = 0; i < n; ++i) {
			int j = dsu.getc(i);
			++cou[j][str[i] - 'a'];
			++cou[j][C];
		}
		int res = 0;
		for (int i = 0; i < n; ++i) {
			int add = cou[i][C];
			for (int c = 0; c < C; ++c) {
				add = min(add, cou[i][C] - cou[i][c]);
				cou[i][c] = 0;
			}
			cou[i][C] = 0;
			res += add;
		}
		cout << res << '\n';
	}
}