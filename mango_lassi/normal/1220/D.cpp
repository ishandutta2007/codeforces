#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const int H = 100;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// if a, b \in b, then a/gcd(a, b) + b/(gcd(a, b) must be even
	// -> works IFF all numbers are divisible by same power of two

	int n;
	cin >> n;
	vector<int> cou(H, 0);
	vector<ll> bs(n);
	for (int i = 0; i < n; ++i) {
		cin >> bs[i];

		ll tmp = bs[i];
		for (int j = 0; j < H; ++j) {
			if (tmp & 1) {
				++cou[j];
				break;
			}
			tmp >>= 1;
		}
	}
	pair<int, int> res = {n, -1};
	for (int j = 0; j < H; ++j) {
		pair<int, int> off = {n - cou[j], j};
		res = min(res, off);
	}

	cout << res.first << '\n';
	for (ll v : bs) {
		ll tmp = v;
		for (int j = 0; j < H; ++j) {
			if (tmp & 1) {
				if (j != res.second) cout << v << ' ';
				break;
			}
			tmp >>= 1;
		}
	}
	cout << '\n';
}