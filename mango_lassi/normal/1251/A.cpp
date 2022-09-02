#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int C = 26;

void solve() {
	string str;
	cin >> str;
	int n = str.size();

	vector<bool> can(C, true);
	for (int i = 0; i < n; ++i) {
		if (i+1 == n) can[str[i] - 'a'] = false;
		else if (str[i+1] == str[i]) ++i;
		else can[str[i] - 'a'] = false;
	}
	for (int i = 0; i < C; ++i) {
		if (can[i] == false) cout << (char)('a' + i);
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}