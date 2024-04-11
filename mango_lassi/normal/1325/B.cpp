#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		int n;
		cin >> n;

		vector<int> vals(n);
		for (int& v : vals) cin >> v;

		sort(vals.begin(), vals.end());
		vals.erase(unique(vals.begin(), vals.end()), vals.end());
		cout << vals.size() << '\n';
	}
}