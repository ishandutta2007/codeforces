#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

const int N = 3 * (int)1e5;
ll val[N];
ll dp[N];
ll bb[N];
vector<int> conns[N];

// Calc ans
void solve(int i, int p) {
	dp[i] = val[i];
	bb[i] = -INF;
	for (auto t : conns[i]) {
		if (t == p) continue;
		solve(t, i);
		dp[i] += max(0ll, dp[t]);
		bb[i] = max(bb[i], bb[t]);
	}
	bb[i] = max(bb[i], dp[i]);
}

// Calc cou
// Flood fill in DFS order
int count(int i, int p, ll req) {
	int res = 0;
	dp[i] = val[i];
	for (auto t : conns[i]) {
		if (t == p) continue;
		res += count(t, i, req);
		dp[i] += max(0ll, dp[t]);
	}
	if (dp[i] == req) {
		dp[i] = 0;
		++res;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> val[i];
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	
	solve(0, 0);
	ll ans = bb[0];
	int cou = count(0, 0, ans);
	cout << ans * cou << ' ' << cou << '\n';
}