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

		vector<int> a(n), b(n);
		for (int& v : a) cin >> v;
		for (int& v : b) cin >> v;
		
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		for (auto v : a) cout << v << ' '; cout << '\n';
		for (auto v : b) cout << v << ' '; cout << '\n';
	}
}