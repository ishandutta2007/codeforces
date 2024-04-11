#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// Initially round all down, then round all those that 
	ll sum = 0;
	vector<pair<ll, bool>> nums(n);
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;

		ll v = 0;
		int j = 0;
		int mn = (str[0] == '-') ? -1 : 1;
		if (mn == -1) ++j;

		for (; str[j] != '.'; ++j) {
			v = (v * 10 + (str[j] - '0'));
		}

		nums[i].second = false;
		for (++j; j < str.size(); ++j) {
			if (str[j] != '0') nums[i].second = true;
		}

		nums[i].first = mn * v;
		if (mn == -1 && nums[i].second) --nums[i].first;
		sum += nums[i].first;
	}
	for (int i = 0; i < n; ++i) {
		if (sum < 0 && nums[i].second) {
			++sum;
			cout << nums[i].first + 1 << '\n';
		} else {
			cout << nums[i].first << '\n';
		}
	}
}