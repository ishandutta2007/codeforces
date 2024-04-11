#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> p(n), q(n); // The two permutations
	for (int i = 0; i < n; ++i) cin >> p[i];
	for (int i = 0; i < n; ++i) cin >> q[i];

	string res(n, '_'); // Result string
	int cur = 0; // Index of current letter
	int sd = 0; // symmetric difference
	vector<int> bits(n, 0); // Is letter i in exactly one of the sets

	for (int i = 0; i < n; ++i) {
		for (int j : {p[i]-1, q[i]-1}) {
			sd += 1 - 2*bits[j]; // update symmetric difference
			bits[j] ^= 1; // update bits
			res[j] = 'a' + min(cur, 25); // update result string
		}
		if (sd == 0) ++cur; // symmetric difference 0, sets are equal
	}

	if (cur < k) cout << "NO\n";
	else cout << "YES\n" << res << '\n';
}