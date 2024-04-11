#include <iostream>
using namespace std;

typedef long long ll;
const int N = 10 + (1e5);
int above[N];
int maxim[N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> above[i];
		maxim[i] = max(maxim[i-1], above[i]);
	}
	ll res = 0;
	int x = maxim[n] + 1;
	for (int j = n; j > 0; --j) {
		res += x - (above[j] + 1);
		if (x > maxim[j-1] + 1) {
			--x;
		}
	}
	cout << res << '\n';
}