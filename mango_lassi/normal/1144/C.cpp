#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());

	bool fail = false;
	vector<int> sa = {nums[0]};
	vector<int> sb;
	for (int i = 1; i < n; ++i) {
		if (nums[i] != nums[i-1]) {
			sa.push_back(nums[i]);
		} else if (sb.empty() || (sb.back() != nums[i])) {
			sb.push_back(nums[i]);
		} else {
			fail = true;
		}
	}

	if (fail) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
		cout << sa.size() << '\n';
		for (auto v : sa) cout << v << ' '; cout << '\n';
		cout << sb.size() << '\n';
		for (int i = (int)sb.size() - 1; i >= 0; --i) cout << sb[i] << ' '; cout << '\n';
	}
}