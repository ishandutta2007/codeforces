#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

bool ok(int v) {
	string str;
	while(v > 0) {
		str.push_back('0' + (v % 10));
		v /= 10;
	}
	for (int i = 0; i < str.size(); ++i) {
		for (int j = i+1; j < str.size(); ++j) {
			if (str[i] == str[j]) return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int l, r;
	cin >> l >> r;

	int x = l;
	for (; x <= r; ++x) {
		if (ok(x)) break;
	}
	if (x <= r) cout << x << '\n';
	else cout << -1 << '\n';
}