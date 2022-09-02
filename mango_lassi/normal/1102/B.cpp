#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> nums(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i].first;
		nums[i].second = i;
	}
	sort(nums.begin(), nums.end());

	int si = 0;
	int ci = 0;
	int pc = -1;
	vector<int> res(n);
	bool fail = false;
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i].first != pc) {
			pc = nums[i].first;
			ci = si;
			res[nums[i].second] = si;
			si = (si + 1) % k;
		} else {
			if (si == ci) {
				fail = true;
				break;
			}
			res[nums[i].second] = si;
			si = (si + 1) % k;
		}
	}
	if (fail) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for (auto v : res) cout << v+1 << ' '; cout << '\n';
	}
}