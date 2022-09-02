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

	int odds = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (a % 2 != 0) {
			if (a < 0) {
				if (odds % 2) {
					cout << (a / 2) << '\n';
				} else {
					cout << (a-1) / 2 << '\n';
				}
			} else {
				if (odds % 2) {
					cout << (a+1) / 2 << '\n';
				} else {
					cout << a / 2 << '\n';
				}
			}
			odds = 1 - odds;
		} else cout << a/2 << '\n';
	}
}