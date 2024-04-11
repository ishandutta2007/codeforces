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
	vector<int> odds;
	vector<int> evens;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		if (v % 2 == 0) evens.push_back(v);
		else odds.push_back(v);
	}
	sort(odds.begin(), odds.end());
	sort(evens.begin(), evens.end());

	if (odds.size() > evens.size()) {
		swap(odds, evens);
	}

	while(! evens.empty()) {
		evens.pop_back();
		if (odds.empty()) {
			break;
		} else {
			odds.pop_back();
		}
	}
	ll sum = 0;
	for (auto v : evens) sum += v;
	cout << sum << '\n';
}