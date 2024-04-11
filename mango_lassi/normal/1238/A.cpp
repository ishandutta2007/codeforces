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
		ll a, b;
		cin >> a >> b;
		if (a >= b + 2) cout << "YES\n";
		else cout << "NO\n";
	}
}