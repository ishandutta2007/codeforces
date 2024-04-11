#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5;
int state[N+2][2];

int count(int x, int y) {
	return state[x-1][y^1] + state[x][y^1] + state[x+1][y^1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	int res = 0;
	for (int j = 0; j < q; ++j) {
		int y, x;
		cin >> y >> x;
		--y;

		if (state[x][y]) res -= count(x, y);
		else res += count(x, y);
		state[x][y] ^= 1;

		if (res == 0) cout << "Yes\n";
		else cout << "No\n";
	}
}