#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll x, y, z, t1, t2, t3;
	cin >> x >> y >> z >> t1 >> t2 >> t3;
	ll elt = t2 * (abs(x - z) + abs(y - x)) + 3 * t3;
	ll stt = t1 * abs(x - y);
	if (elt <= stt) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}