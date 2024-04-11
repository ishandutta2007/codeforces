#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << (n*j + ((j & 1) ? n-i-1 : i)) + 1 << ' ';
		}
		cout << '\n';
	}

	// optimal to have all n back-to-back, and reverse the internal permutations
}