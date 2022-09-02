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

	int odd = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		odd += (x & 1);
	}
	cout << min(odd, n - odd) << '\n';
}