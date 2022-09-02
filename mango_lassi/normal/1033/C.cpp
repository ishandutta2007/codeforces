#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

const int N = 2 * (int)1e5;
int win[N];
int ind[N + 1];
int val[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> val[i];
		ind[val[i]] = i;
	}
	for (int v = n; v >= 1; --v) {
		int j = ind[v];
		win[j] = -1;
		for (int i = j - v; i >= 0; i -= v) {
			if (win[i] == -1) win[j] = 1;
		}
		for (int i = j + v; i < n; i += v) {
			if (win[i] == -1) win[j] = 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (win[i] == 1) {
			cout << "A";
		} else {
			cout << "B";
		}
	}
	cout << '\n';
}