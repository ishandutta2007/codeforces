#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;

	int n = str.size();
	int as = 0;
	for (auto c : str) {
		if (c == 'a') ++as;
	}
	int m = (n + as) / 2;

	bool fail = false;
	if (m == 0) {
		fail = true;
	} else {
		int j = m;
		for (int i = 0; i < m; ++i) {
			if (str[i] == 'a') continue;
			if (str[i] != str[j]) fail = true;
			++j;
		}
		if (j != n) fail = true;
	}

	if (fail) {
		cout << ":(" << '\n';
	} else {
		for (int i = 0; i < (n + as) / 2; ++i) {
			cout << str[i];
		}
		cout << '\n';
	}
}