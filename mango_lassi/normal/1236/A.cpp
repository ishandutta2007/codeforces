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
	for (int ti = 0; ti < n; ++ti) {
		int a, b, c;
		cin >> a >> b >> c;
		int res = min(b, c / 2);
		b -= res;
		res += min(a, b / 2);
		cout << 3*res << '\n';
	}
}