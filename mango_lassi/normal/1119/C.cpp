#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 500;
int cols[N];
int rows[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;

	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			int v;
			cin >> v;
			cols[x] ^= v;
			rows[y] ^= v;
		}
	}
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			int v;
			cin >> v;
			cols[x] ^= v;
			rows[y] ^= v;
		}
	}

	bool fail = false;
	for (int i = 0; i < N; ++i) {
		if (cols[i] != 0) fail = true;
		if (rows[i] != 0) fail = true;
	}
	if (fail) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
	}
}