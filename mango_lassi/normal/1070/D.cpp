#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;

	int pre = 0;
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		int cur;
		cin >> cur;

		res += pre / k;
		pre %= k;

		if (pre > 0) {
			++res;
			cur = max(cur - (k - pre), 0); 
		}
		pre = cur;
	}
	res += pre / k;
	pre %= k;
	if (pre > 0) ++res;
	cout << res << '\n';
}