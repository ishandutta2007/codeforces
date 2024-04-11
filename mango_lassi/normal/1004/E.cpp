#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

const ll INF = 1e9 + 7;
const int N = 1e5;
vector<int> conns[N];
vector<int> costs[N];
bool shop[N];

pair<ll, int> dfs(int i, int p) {
	ll dep = 0;
	pair<ll, int> res = {0, i};
	for (int ti = 0; ti < conns[i].size(); ++ti) {
		int t = conns[i][ti];
		int c = costs[i][ti];
		if  (t == p) continue;
		if (shop[t]) continue;
		pair<ll, int> sub = dfs(t, i);
		sub.first += c;
		res = max(res, sub);
	}
	return res;
}
bool dfs2(int i, int p, int b, vector<int>& els, vector<int>& pri) {
	if (i == b) {
		els.push_back(i);
		pri.push_back(0);
		return true;
	}
	for (int ti = 0; ti < conns[i].size(); ++ti) {
		int t = conns[i][ti];
		int c = costs[i][ti];
		if (t == p) continue;
		if (dfs2(t, i, b, els, pri)) {
			els.push_back(i);
			pri.push_back(c);
			return true;
		}
	}
	return false;
}

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n-1; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
		costs[a].push_back(c);
		costs[b].push_back(c);
	}
	int a = dfs(0, 0).second;
	int b = dfs(a, a).second;

	vector<int> pri;
	vector<int> els;
	dfs2(a, a, b, els, pri);
	
	int m = pri.size();
	vector<ll> pref(m);
	vector<ll> posf(m);

	for (int i = 0; i < m-1; ++i) {
		pref[i+1] = pref[i] + pri[i+1];
	}
	for (int i = m-1; i > 0; --i) {
		posf[i-1] = posf[i] + pri[i];
	}
	/*
	for (auto v : pri) cout << v << ' '; cout << '\n';
	for (auto v : pref) cout << v << ' '; cout << '\n';
	for (auto v : posf) cout << v << ' '; cout << '\n';
	*/
	ll best = INF;
	int best_a = -1;
	int best_b = -1;
	k = min(k, m);
	for (int i = 0; i + k <= m; ++i) {
		ll offer = max(pref[i], posf[i + k - 1]);
		if (offer < best) {
			best_a = i;
			best_b = i + k - 1;
			best = offer;
		}
	}
	ll res = 0;
	for (int i = best_a; i <= best_b; ++i) shop[els[i]] = true;
	for (int i = best_a; i <= best_b; ++i) res = max(res, dfs(els[i], els[i]).first);
	cout << res << '\n';
}