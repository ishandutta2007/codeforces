#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void solve() {
	string str;
	cin >> str;
	int n = str.size();

	string odds, evens;
	for (int i = 0; i < n; ++i) {
		if ((str[i] - '0') & 1) odds.push_back(str[i]);
		else evens.push_back(str[i]);
	}

	int a = 0, b = 0;
	for (int i = 0; i < n; ++i) {
		bool pa = false;
		if (a < odds.size() && b < evens.size()) {
			if (odds[a] < evens[b]) pa = true;
		} else if (b >= evens.size()) pa = true;

		if (pa) {
			str[i] = odds[a];
			++a;
		} else {
			str[i] = evens[b];
			++b;
		}
	}
	cout << str << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}