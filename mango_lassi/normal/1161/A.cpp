#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = (int)1e5;
int fi[N];
int la[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		fi[i] = k+1;
		la[i] = -1;
	}
	for (int j = 0; j < k; ++j) {
		int i;
		cin >> i;
		--i;
		fi[i] = min(fi[i], j);
		la[i] = max(la[i], j);
	}

	ll res = 0;
	for (int i = 0; i < n; ++i) {
		if (i > 0) {
			if (fi[i] > la[i-1]) {
				// cout << i << ' ' << i-1 << '\n';
				++res;
			}
		}
		if (i+1 < n) {
			if (fi[i] > la[i+1]) {
				// cout << i << ' ' << i+1 << '\n';
				++res;
			}
		}
		if (fi[i] > la[i]) {
			// cout << i << ' ' << i << '\n';
			++res;
		}
	}
	cout << res << '\n';
}