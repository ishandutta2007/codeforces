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

	if (n % 2 == 1) {
		cout << "YES\n";
		for (int i = 0; i < n; ++i) cout << (2*i+1 + (i & 1)) << ' ';
		for (int i = 0; i < n; ++i) cout << (2*i+1 + 1 - (i & 1)) << ' ';
		cout << '\n';
	} else {
		cout << "NO\n";
	}
}