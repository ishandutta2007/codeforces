#include <iostream>
using namespace std;

const int N = 5000;
int val[N][N];
int res[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> val[i][i];
		res[i][i] = val[i][i];
	}
	for (int len = 1; len < n; ++len) {
		for (int a = 0; a + len < n; ++a) {
			int le = val[a][a + len - 1];
			int ri = val[a + 1][a + len];
			val[a][a + len] = le ^ ri;
			res[a][a + len] = std::max(val[a][a + len], std::max(res[a][a + len - 1], res[a + 1][a + len]));
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		--l; --r;
		cout << res[l][r] << '\n';
	}
}