#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e4;
const int M = 50;
vector<int> apps[N];
bool edg[M][M];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Always possible unless on some day dora picks a subset of what the monkey picked on some other day.
	// To do this, for every day, multiply the integers of the stores dora visits by some prime p
	// unique for that day. The value dora gets is always the product of all primes, but monkey can only get
	// the product of all primes except the one from the current day.

	int m, n;
	cin >> m >> n;

	bool fail = false;
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		for (int ind = 0; ind < k; ++ind) {
			int a;
			cin >> a;
			--a;

			for (auto j : apps[a]) edg[i][j] = true;
			apps[a].push_back(i);
		}
		for (int j = 0; j < i; ++j) {
			if (! edg[i][j]) fail = true;
		}
	}
	if (fail) cout << "impossible\n";
	else cout << "possible\n";
}