#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define sz(a) int((a).size())
#define vi vector<int>
typedef long long ll;
const int N = 1e4 + 10;
int n, a[N], b[N];
bitset<N> dp;
void solve() {
	cin >> n;
	ll sum = 0, all = 0;
	for(int i = 1; i <= n; i++) cin >> a[i], sum += a[i] * a[i] * (n - 2), all += a[i];
	for(int i = 1; i <= n; i++) cin >> b[i], sum += b[i] * b[i] * (n - 2), all += b[i];
	dp.reset();
	dp[0] = 1;
	for(int i = 1; i <= n; i++) dp = (dp << a[i]) | (dp << b[i]);
	ll ans = 1e18;
	for(int i = 0; i <= n * 100; i++) {
		if(dp[i]) {
			ans = min(ans, 1ll * i * i + 1ll * (all - i) * (all - i));
		}
	}
	cout << ans + sum << endl;
	return;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	for(cin >> t; t--; solve());
    return 0;
}