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

	int res = 0;
	int v0 = 0;
	int v1 = 0;
	int pre = -1;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		if (v == pre) {
			++v1;
		} else {
			pre = v;
			v0 = v1;
			v1 = 1;
		}
		res = max(res, min(v0, v1));
	}
	cout << 2*res << '\n';
}