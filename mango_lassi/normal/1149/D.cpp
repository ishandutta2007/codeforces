#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
using ll = long long;
const ll INF = 1e18;

const int M = 17; // At most 17 components of size 4 or more
const int N = 70;
int ci[N];
int cs[N];
int cm[N];
vector<int> cheap[N];
vector<int> tall[N];
ll dp[N * (1<<M)];

int getInd(int i, int mask) {
	return i + mask * N;
}
int getI(int ind) {
	return ind % N;
}
int getMask(int ind) {
	return ind / N;
}
bool canMove(int i, int t, int mask, bool ee) {
	if (ee && (ci[i] == ci[t])) return false;
	else if (ci[i] == ci[t]) return true;
	if (cm[ci[t]] == -1) return true;
	if (mask & (1<<cm[ci[t]])) return false;
	else return true;
}
int modMask(int i, int t, int mask) {
	if (cm[ci[i]] == -1 || ci[i] == ci[t]) return mask;
	else return mask | (1<<cm[ci[i]]);
}

void dfs1(int i, int g) {
	ci[i] = g;
	++cs[g];
	for (auto t : cheap[i]) {
		if (ci[t] == -1) dfs1(t, g);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, a, b;
	cin >> n >> m >> a >> b;
	for (int j = 0; j < m; ++j) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		int c;
		cin >> c;
		if (c == a) {
			cheap[u].push_back(v);
			cheap[v].push_back(u);
		} else {
			tall[u].push_back(v);
			tall[v].push_back(u);
		}
	}

	int comps = 0;
	int big_comps = 0;
	for (int i = 0; i < n; ++i) ci[i] = -1;

	for (int i = 0; i < n; ++i) {
		if (ci[i] == -1) {
			dfs1(i, comps);
			if (cs[comps] >= 4) {
				cm[comps] = big_comps;
				++big_comps;
			} else {
				cm[comps] = -1;
			}
			++comps;
		}
	}

	int mm = 1<<big_comps;
	for (int i = 0; i < n; ++i) {
		for (int mask = 0; mask < mm; ++mask) {
			dp[getInd(i, mask)] = INF;
		}
	}
	dp[getInd(0, 0)] = 0;
	
	priority_queue<pair<ll, int>> que;
	que.push({0, getInd(0, 0)});
	while(! que.empty()) {
		int ind = que.top().second;
		ll co = -que.top().first;
		que.pop();

		if (co != dp[ind]) continue;

		int i = getI(ind);
		int mask = getMask(ind);

		for (auto t : cheap[i]) {
			if (! canMove(i, t, mask, false)) continue;
			int t_mask = modMask(i, t, mask);
			int t_ind = getInd(t, t_mask);
			ll off = co + a;
			if (off < dp[t_ind]) {
				dp[t_ind] = off;
				que.push({-off, t_ind});
			}
		}
		for (auto t : tall[i]) {
			if (! canMove(i, t, mask, true)) continue;
			int t_mask = modMask(i, t, mask);
			int t_ind = getInd(t, t_mask);
			ll off = co + b; // Only difference to last block
			if (off < dp[t_ind]) {
				dp[t_ind] = off;
				que.push({-off, t_ind});
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		ll res = INF;
		for (int mask = 0; mask < mm; ++mask) {
			int ind = getInd(i, mask);
			if (dp[ind] < res) res = dp[ind];
		}
		cout << res << ' ';
	}
	cout << '\n';
}