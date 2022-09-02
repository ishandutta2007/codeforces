#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> le(n);
	for (int i = 0; i < n; ++i) cin >> le[i];
	vector<int> up(n);
	for (int i = 0; i < n; ++i) cin >> up[i];

	vector<tuple<int, int, int, int>> res;
	for (int j = 0; j < n; ++j) {
		int a = j;
		int b = j;
		for (; a < n; ++a) {
			if (le[a] == j+1) break;
		}
		for (; b < n; ++b) {
			if (up[b] == j+1) break;
		}
		if (a != j || b != j) {
			res.push_back({a+1, j+1, j+1, b+1});
			swap(le[a], le[j]);
			swap(up[b], up[j]);
		}
	}
	cout << res.size() << '\n';
	for (int i = 0; i < res.size(); ++i) {
		int x1, y1, x2, y2;
		tie(x1, y1, x2, y2) = res[i];
		cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
	}
}