#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = (ll)1e16;

// 0  0  0  0  0
// 1  2  4  8  16 
// 0  0  0  0  0
// 4  8  16 32 64
// 0  0  0  0  0
// 16 32 64 ...

const int N = 25;
ll arr[N][N];

void solve() {
	int n;
	cin >> n;

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			cout << arr[y][x] << ' ';
		}
		cout << endl;
	}

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		ll val;
		cin >> val;

		int x = 0, y = 0;
		cout << y+1 << ' ' << x+1 << endl;

		while(x < n-1 || y < n-1) {
			if (x+1 == n) ++y;
			else if (y+1 == n) ++x;
			else {
				ll v1 = arr[y][x+1];
				ll v2 = arr[y+1][x];
				if (v1 > 0) {
					if (val & v1) ++x;
					else ++y;
				} else {
					if (val & v2) ++y;
					else ++x;
				}
			}
			cout << y+1 << ' ' << x+1 << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int y = 1; y < N; y += 2) {
		for (int x = 0; x < N; ++x) {
			ll pw = x + (y - 1);
			arr[y][x] = 1ll << pw;
		}
	}

	solve();
}