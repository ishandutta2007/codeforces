#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

char flip(char c) {
	return c == 'B' ? 'W' : 'B';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string str;
	cin >> str;

	int cou = 0;
	for (auto c : str) cou += (c == 'B');

	char t = 'W';
	if (n % 2 == 1 && cou % 2 == 1) {
		t = flip(t);
		cou ^= 1;
	}

	if (cou % 2 == 0) {
		vector<int> res;
		for (int i = 0; i+1 < n; ++i) {
			if (str[i] != t) {
				res.push_back(i);
				str[i] = flip(str[i]);
				str[i+1] = flip(str[i+1]);
			}
		}
		cout << res.size() << '\n';
		for (auto i : res) cout << i+1 << ' '; cout << '\n';
	} else {
		cout << "-1\n";
	}
}