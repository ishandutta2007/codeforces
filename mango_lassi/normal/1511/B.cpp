#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int a, b, c;
		cin >> a >> b >> c;

		string sa(a, '0'), sb(b, '0');
		sa[0] = '1';
		sb[0] = '1';
		sa[a-c] = '1';
		cout << sa << ' ' << sb << '\n';
	}
}