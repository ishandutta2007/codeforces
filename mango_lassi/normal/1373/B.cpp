#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	string str;
	cin >> str;

	int n = str.size();
	int turns = 0;
	for (auto c : str) turns += (c == '1');

	turns = min(turns, n - turns);
	if (turns & 1) cout << "DA\n";
	else cout << "NET\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}