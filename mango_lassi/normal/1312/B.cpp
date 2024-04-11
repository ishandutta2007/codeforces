#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int n;
		cin >> n;
		vector<int> vals(n);
		for(int& a : vals) cin >> a;
		sort(vals.begin(), vals.end());
		reverse(vals.begin(), vals.end());
		for (int a : vals) cout << a << ' '; cout << '\n';
	}
}