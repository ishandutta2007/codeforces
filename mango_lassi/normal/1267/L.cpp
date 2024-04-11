#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, l, k;
	cin >> n >> l >> k;
	--k;

	string str;
	cin >> str;
	sort(str.begin(), str.end());

	vector<string> res(n);
	int x = 0;
	int a = 0;
	int b = (int)str.size() - 1;
	for (int i = 0; i < l; ++i) {
		for (int j = n-1; j >= 0; --j) {
			if (j < x || k < j) {
				res[j].push_back(str[b]);
				--b;
			}
		}
		for (int j = 0; j < n; ++j) {
			if (j >= x && j <= k) {
				if (j > x && str[a] != str[a-1]) x = j;
				res[j].push_back(str[a]);
				++a;
			}
		}
	}
	for (int j = 0; j < n; ++j) cout << res[j] << '\n';
}