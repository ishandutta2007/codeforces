#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 1e18;

void solve() {
	int n;
	cin >> n;
	vector<ll> dp(3, 0);
	int pa = -1;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		vector<ll> nxt(3, INF);
		for (int x = 0; x < 3; ++x) {
			for (int y = 0; y < 3; ++y) {
				if (pa + x != a + y) nxt[y] = min(nxt[y], dp[x] + (ll)y*b);
			}
		}
		dp = nxt;
		pa = a;
	}
	cout << min(min(dp[0], dp[1]), dp[2]) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) solve();
}