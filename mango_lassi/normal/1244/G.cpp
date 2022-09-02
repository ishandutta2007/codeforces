#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll add(ll j, ll n) {
	return 2*((n-j) - (j+1));
}
ll inc(ll a, ll n) {
	return (2*a+n-1) * n / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n, k;
	cin >> n >> k;
	ll ini_k = k;
	k -= n * (n+1) / 2;

	if (k < 0) {
		cout << "-1\n";
	} else {
		// To get even sum, make an even number of odd elements into maximums
		// To get odd sum, do same with odd number.
		// Fix first perm to be identity. Use second to make res as large as possible.
		// Place largest and smallest as long as we can
		vector<int> res(n, -1);
		int j = 0;
		for (int i = 0; i < n; ++i) {
			int a = i;
			int b = n-i-1;
			if (k > 0 && b >= a) {
				if (k >= b-a) {
					res[b] = i+1;
					k -= b-a;
				} else {
					res[a + k] = i+1;
					k = 0;
				}
			} else {
				while(res[j] != -1) ++j;
				res[j] = i+1;
			}
		}
		cout << ini_k - k << '\n';
		for (int i = 0; i < n; ++i) cout << i+1 << ' '; cout << '\n';
		for (auto v : res) cout << v << ' '; cout << '\n';
	}
}