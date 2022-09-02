#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll r;
	cin >> r;
	if (r % 2 == 1) {
		r -= 3;
		if (r <= 0) cout << "NO\n";
		else {
			cout << 1 << ' ' << r/2 << '\n';
		}
	} else {
		cout << "NO\n";
	}
}