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
	
	ll pos = 1; // 0
	ll neg = 0;
	int cur = 1;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (a < 0) cur *= -1;
		if (cur < 0) ++neg;
		else ++pos;
	}
	cout << neg * pos << ' ' << neg * (neg - 1) / 2 + pos * (pos - 1) / 2 << '\n';
}