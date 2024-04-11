#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

map<int, int> last;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
		last[nums[i]] = max(i, last[nums[i]]);
	}

	// Just find number of spots where no number from before appears again
	ll res = 1;
	int e = 0;
	for (int i = 0; i < n; ++i) {
		if (e < i) res = (res * 2) % MOD;
		e = max(e, last[nums[i]]);
	}
	cout << res << '\n';
}