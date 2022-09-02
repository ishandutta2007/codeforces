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

	vector<bool> used(n, false);
	vector<int> ind(n);
	for (int i = 0; i < n; ++i) {
		int j;
		cin >> j;
		ind[j-1] = i;
	}
	int res = 0;
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		int j;
		cin >> j;
		if (ind[j-1] != cur) {
			++res;
		}
		used[ind[j-1]] = true;
		while(cur < n && used[cur]) ++cur;
	}
	cout << res << '\n';
}