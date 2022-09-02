#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 5 * (int)1e5;
vector<pair<int, ll>> conns[N];
ll dp1[N]; // NO edge to parent
ll dp2[N]; // YES edge to parent

void recSolve(int i, int p, int k) {
	ll sum = 0;

	vector<ll> offs;
	for (auto ed : conns[i]) {
		int t = ed.first;
		if (t == p) continue;

		recSolve(t, i, k);
		sum += dp1[t];
		offs.push_back(dp2[t] + ed.second - dp1[t]);
	}
	sort(offs.begin(), offs.end());

	int m = offs.size();
	offs.push_back(0);
	for (int i = m-1; i >= 0; --i) {
		offs[i] = max(offs[i+1], offs[i] + offs[i+1]);
	}
	
	dp1[i] = sum + (m >= k ? offs[m-k] : offs[0]);
	dp2[i] = sum + (m >= k-1 ? offs[m-(k-1)] : offs[0]);
}

void solve() {
	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		ll w;
		cin >> a >> b >> w;
		--a; --b;
		conns[a].emplace_back(b, w);
		conns[b].emplace_back(a, w);
	}

	recSolve(0, 0, k);
	cout << dp1[0] << '\n';

	for (int i = 0; i < n; ++i) {
		dp1[i] = 0;
		dp2[i] = 0;
		conns[i].clear();
		conns[i].shrink_to_fit();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) solve();

}