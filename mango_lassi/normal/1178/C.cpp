#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll h, w;
	cin >> h >> w;
	
	ll res = 4;
	for (int x = 1; x < w; ++x) {
		res = (res * 2) % MOD;
	}
	for (int y = 1; y < h; ++y) {
		res = (res * 2) % MOD;
	}
	cout << res << '\n';
}