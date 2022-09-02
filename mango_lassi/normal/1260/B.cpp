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
		int a, b;
		cin >> a >> b;

		if (b <= 2*a && a <= 2*b && ((a+b) % 3 == 0)) cout << "YES\n";
		else cout << "NO\n";
	}
}