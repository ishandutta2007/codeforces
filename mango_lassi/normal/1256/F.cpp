#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int C = 26;

bool parity(const string& str) {
	bool res = true;
	for (int i = 0; i < str.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (str[i] < str[j]) res ^= 1;
		}
	}
	return res;
}

bool solve() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;

	vector<int> cou(C, 0);
	for (auto c : a) ++cou[c - 'a'];
	
	bool same = false;
	for (auto v : cou) same |= (v >= 2);

	for (auto c : b) --cou[c - 'a'];

	bool fail = false;
	for (auto v : cou) fail |= (v != 0);
	
	if (fail) return false;
	if (! same) {
		if (parity(a) != parity(b)) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		bool res = solve();
		if (res) cout << "YES\n";
		else cout << "NO\n";
	}
}