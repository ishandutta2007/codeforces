#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 3 * (int)1e5;
vector<int> conns[N];
ll dp1[N];
ll dp2[N];

void recSolve(int i, int p) {
	ll base = 1;
	ll r1 = 0;
	ll r2 = 0;
	for (auto t : conns[i]) {
		if (t == p) continue;
		recSolve(t, i);

		ll off = dp1[t];
		if (off > r1) swap(off, r1);
		if (off > r2) swap(off, r2);

		dp2[i] = max(dp2[i], dp2[t]);
		++base;
	}
	dp1[i] = r1 + base - (base > 1);
	dp2[i] = max(dp2[i], r1 + r2 + (base - 2) + (p != -1));
}

void solve() {
	int n;
	cin >> n;

	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	recSolve(0, -1);
	cout << max(dp1[0], dp2[0]) << '\n';

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