#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> as(n-1), cou(n, 0), val(n);
	for (int& v : as) {
		cin >> v;
		--v;
		++cou[v];
	}
	priority_queue<pair<int, int>> que;
	for (int i = 0; i < n; ++i) {
		val[i] = i;
		if (cou[i] == 0) que.push({-val[i], i});
	}

	vector<pair<int, int>> res;
	for (int j = n-2; j >= 0; --j) {
		int a = as[j];
		int b = que.top().second;
		que.pop();

		val[a] = max(val[a], val[b]);
		res.push_back({a, b});

		--cou[a];
		if (cou[a] == 0) que.push({-val[a], a});
	}
	
	cout << que.top().second + 1 << '\n';
	for (auto pr : res) cout << pr.first+1 << ' ' << pr.second+1 << '\n';
}