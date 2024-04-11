#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<pair<int, int>> cou(n);
	for (int i = 0; i < n; ++i) {
		int a, f;
		cin >> a; // >> f;
		--a;
		++cou[a].first;
		// if (f == 1) ++cou[a].second;
	}
	sort(cou.begin(), cou.end());

	vector<int> heights;
	int res = 0;
	int cur = n+1;
	for (int i = n-1; (cur > 0) && (i >= 0); --i) {
		cur = min(cou[i].first, cur - 1);
		heights.push_back(cur);
		res += cur;
	}

	/*
	priority_queue<int> act;
	int ind = n-1;
	int res2 = 0;
	for (int j = 0; j < heights.size(); ++j) {
		while(ind >= 0 && cou[ind].first >= heights[j]) {
			act.push(cou[ind].second);
			--ind;
		}
		res2 += min(act.top(), heights[j]);
		act.pop();
	}
	*/
	// cout << res << ' ' << res2 << '\n';
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}