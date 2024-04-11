#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int norm(int v) {
	return (v < 0 ? -1 : (v == 0) ? 0 : 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int ax, ay;
	cin >> ax >> ay;
	int bx, by;
	cin >> bx >> by;
	int cx, cy;
	cin >> cx >> cy;
	if (norm(cx - ax) != norm(bx - ax) || norm(cy - ay) != norm(by - ay)) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}