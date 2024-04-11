#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = (ll)1e9 + 7;

const int N = 2 * (int)1e5;
vector<int> conns[N];
int ini[N];
int tar[N];
ll cost[N];

pair<ll, int> recSolve(int i, int p, ll min_cost) {
	min_cost = min(min_cost, cost[i]);

	ll res = 0;
	int ones = 0, zeros = 0;
	if (ini[i] != tar[i]) {
		if (ini[i] == 0) ++zeros;
		else ++ones;
	}
	for (auto t : conns[i]) {
		if (t == p) continue;
		auto sub = recSolve(t, i, min_cost);
		res += sub.first;
		if (sub.second < 0) zeros -= sub.second;
		else ones += sub.second;
	}
	int k = 2*min(ones, zeros);
	res += k * min_cost;
	return {res, ones - zeros};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> cost[i] >> ini[i] >> tar[i];
		conns[i].clear();
	}

	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}

	auto res = recSolve(0, -1, INF);
	if (res.second != 0) cout << "-1\n";
	else cout << res.first << '\n';
}