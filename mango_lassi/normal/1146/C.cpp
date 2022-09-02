#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int ask(const vector<int>& ga, const vector<int>& gb) {
	cout << ga.size() << ' ' << gb.size();
	for (auto i : ga) cout << ' ' << i+1;
	for (auto i : gb) cout << ' ' << i+1;
	cout << endl;

	int ans;
	cin >> ans;
	if (ans == -1) exit(0);
	return ans;
}

void answer(int v) {
	cout << -1 << ' ' << v << endl;
}

void solve() {
	int n;
	cin >> n;

	int j = 1;
	while((j<<1) < n) j <<= 1;

	int res = 0;
	for (; j > 0; j >>= 1) {
		vector<int> ga;
		vector<int> gb;

		bool group = false;
		for (int i = 0; i < n; ++i) {
			if (i % j == 0) group ^= 1;
			if (group) ga.push_back(i);
			else gb.push_back(i);
		}

		int sub = ask(ga, gb);
		res = max(res, sub);
	}
	answer(res);
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
}