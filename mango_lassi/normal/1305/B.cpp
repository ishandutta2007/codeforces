#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	int n = str.size();

	// No more operations can be perfomed -> Has form )))((((

	vector<int> cou(n+1, 0);
	for (int i = n-1; i >= 0; --i) {
		cou[i] = cou[i+1] + (str[i+1] == ')');
	}

	int cur = 0;
	vector<int> res;
	for (int i = 0; i < n; ++i) {
		if (cou[i] == 0) break;

		if (str[i] == '(') {
			++cur;
			res.push_back(i);
		}
		if (cur == cou[i]) {
			for (int j = i+1; j < n; ++j) {
				if (str[j] == ')') res.push_back(j);
			}
			break;
		}
	}
	if (res.empty()) cout << 0 << '\n';
	else {
		cout << 1 << '\n';
		cout << res.size() << '\n';
		for (auto i : res) cout << i+1 << ' '; cout << '\n';
	}
}