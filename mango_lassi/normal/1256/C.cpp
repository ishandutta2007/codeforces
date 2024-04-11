#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// width platforms jump
	int n, m, d;
	cin >> n >> m >> d;

	int sum = 0;
	vector<int> cs(m);
	for (int i = 0; i < m; ++i) {
			cin >> cs[i];
			sum += cs[i];
	}
	if ((ll)(m+1) * (d-1) + sum >= n) {
		cout << "YES\n";

		int j = 0;
		int p = -1;
		for (int i = 0; i < n; ++i) {
			if (p + d == i || sum == n-i) {
				// Must place here
				for (int x = i; x < i + cs[j]; ++x) {
					cout << j+1 << ' ';
				}
				i += cs[j] - 1;
				sum -= cs[j];
				p = i;
				++j;
			} else {
				cout << 0 << ' ';
			}
		}
		cout << '\n';
	} else {
		cout << "NO\n";
	}
}