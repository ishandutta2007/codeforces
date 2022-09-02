#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3 * (int)1e5;
int px[N + 1];

void solve() {
	int a, b;
	cin >> a >> b;

	if (px[a-1] == b) {
		cout << a << '\n';
	} else if ((b ^ px[a-1]) != a) {
		cout << a + 1 << '\n';
	} else {
		cout << a + 2 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	px[0] = 0;
	for (int i = 1; i <= N; ++i) px[i] = px[i-1] ^ i;

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}