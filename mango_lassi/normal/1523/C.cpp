#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> as(n);
	for (int& a : as) cin >> a;

	// Greedy works?
	//	-> 1 always starts a new level
	//	-> 2, 3, ... always continue as high as possible

	vector<int> stack;
	for (int i = 0; i < n; ++i) {
		if (as[i] == 1) {
			stack.push_back(1);
		} else {
			while(stack.back() + 1 != as[i]) stack.pop_back();
			++stack.back();
		}
		
		cout << stack[0];
		for (int j = 1; j < stack.size(); ++j) cout << '.' << stack[j];
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}