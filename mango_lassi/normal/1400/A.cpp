#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	string str;
	cin >> str;

	int cou = 0;
	for (auto c : str) cou += (c == '1');

	char tc = (cou >= n ? '1' : '0');
	cout << string(n, tc) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}