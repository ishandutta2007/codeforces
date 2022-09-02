#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int mx = -1;
	vector<int> as(n);
	for (int i = 0; i < n; ++i) {
		cin >> as[i];
		mx = max(mx, as[i]);
	}
	int len = 0;
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		if (as[i] == mx) ++cur;
		else cur = 0;
		len = max(len, cur);
	}
	cout << len << '\n';
}