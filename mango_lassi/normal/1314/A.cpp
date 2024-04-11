#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
const int INF = 2 * (int)1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> vec(n);
	for (auto& pr : vec) cin >> pr.first;
	for (auto& pr : vec) cin >> pr.second;
	sort(vec.begin(), vec.end());
	vec.push_back({INF, 0});

	ll cur = 0, res = 0;
	priority_queue<int> que;
	for (int i = 0; i < n; ++i) {
		cur += vec[i].second;
		que.push(vec[i].second);
		for (int j = 0; (! que.empty()) && (j < vec[i+1].first - vec[i].first); ++j) {
			int val = que.top();
			que.pop();
			cur -= val;
			res += cur;
		}
	}
	cout << res << '\n';
}