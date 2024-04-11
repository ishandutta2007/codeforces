#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX = 1e6;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k;
	cin >> k;

	// Our sequence can have length at most 2000
	// First put a ton of zeroes, then one -1, then a large number 

	for (int v = 1000;; ++v) {
		int a, b, c, d;
		c = -1;
		d = (k / v) + 2;
		a = v;
		b = (a*(d-1)) - k;
		if (a + b <= 2000 && d <= MAX) {
			cout << a+b << '\n';

			for (int i = 0; i < a-1; ++i) {
				cout << "0 ";
			}
			cout << "-1 ";

			cout << d << ' ';
			for (int i = 1; i < b; ++i) {
				cout << "0 ";
			}
			cout << '\n';

			break;
		}
	}
}