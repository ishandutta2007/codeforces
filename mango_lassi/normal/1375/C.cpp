#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> vals(n);
	for (int& v : vals) cin >> v;

	// Possible when leftmost is larger than rightmost
	// Color red if larger than rightmost, blue otherwise
	//	-> Cannot make a RB-operation
	// 	-> Impossible if rightmost is R

	if (vals[0] > vals[n-1]) cout << "NO\n";
	else cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}