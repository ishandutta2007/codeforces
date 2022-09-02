#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;

int main() {
	int n; ll m;
	cin >> n >> m;
	vector<pair<int, pair<int, int>>> probs;
	for (int i = 0; i < n; ++i) {
		int a, t;
		cin >> a >> t;
		probs.push_back({t, {a, i+1}});
	}
	sort(probs.begin(), probs.end());
	int low = 0;
	int high = n;
	while(low != high) {
		int mid = ((low + high + 1) >> 1);
		ll usd = 0;
		int cou = 0;
		for (auto it : probs) {
			if (mid <= it.second.first) {
				usd += it.first;
				if (m < usd) break;
				++cou;
			}
		}
		if (cou < mid) {
			high = mid - 1;
		} else {
			low = mid;
		}
	}
	cout << low << '\n' << low << '\n';
	int cou = 0;
	for (auto it : probs) {
		if (cou >= low) break;
		if (low <= it.second.first) {
			++cou;
			cout << it.second.second << ' ';
		}
	}
	cout << '\n';
}