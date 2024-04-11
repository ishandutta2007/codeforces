#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

const int N = 1e5;
vector<int> conns[N];
ll sum[N];
ll mins[N];
ll res = 0;

bool dfs(int i, ll ps) {
	if (sum[i] != -1) {
		res += sum[i] - ps;
		if (ps > sum[i]) return false;
		for (auto t : conns[i]) {
			if (! dfs(t, sum[i])) return false;
		}
		return true;
	} else {
		ll mn = INF;
		for (auto t : conns[i]) {
			mn = min(mn, sum[t] - ps);
		}
		if (mn < 0) return false;
		if (mn == INF) mn = 0;
		res += mn;
		for (auto t : conns[i]) {
			if (! dfs(t, ps + mn)) return false;
		}
		return true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		--p;
		conns[p].push_back(i);
	}

	// At every node, pick smallest value in subtree - value on path from root
	for (int i = 0; i < n; ++i) cin >> sum[i];
	bool succ = dfs(0, 0);
	if (succ) {
		cout << res << '\n';
	} else {
		cout << "-1\n";
	}
}