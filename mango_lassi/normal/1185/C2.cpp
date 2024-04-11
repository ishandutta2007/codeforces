#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int T = 101;
int cou[T];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;

		sum += t;
		int tmp = sum - m; // Must reduce at least this much
		int res = 0;
		for (int j = T-1; j > 0; --j) {
			int c = max(0, min(cou[j], (tmp + (j-1)) / j));
			res += c;
			tmp -= j * c;
			if (tmp <= 0) {
				cout << res << ' ';
				break;
			}
		}
		++cou[t];
	}
	cout << '\n';
}