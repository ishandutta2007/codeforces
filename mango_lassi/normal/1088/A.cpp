#include <iostream>
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll x;
	cin >> x;
	if (x == 1) {
		cout << "-1\n";
	} else {
		cout << x << ' ' << x << '\n';
	}
}