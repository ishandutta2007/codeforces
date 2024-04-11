#include <bits/stdc++.h>
#define i64 long long
using namespace std;
const int N = 1e4 + 10;
int n, l, r, a[N], b[N], sum[N], tot = 0;
bitset<N> dp[2];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> l >> r;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		if(b[i]) a[++tot] = a[i];
		else dp[0] |= dp[0] << a[i];
	}
	sort(a + 1, a + tot + 1);
	for(int i = 1; i <= tot; i++) sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for(int i = tot; i >= 0; i--) {
		int p0 = dp[0]._Find_next(l - 1), p1 = dp[1]._Find_next(l - 1);
		int q0 = upper_bound(sum + 1, sum + tot + 1, r - p0) - sum;
		int q1 = upper_bound(sum + 1, sum + tot + 1, r - p1) - sum;
		q0--, q1--;
		q0 = min(q0, i), q1 = min(q1, i);
		if(p0 <= r) ans = max(ans, q0);
		if(p1 <= r) ans = max(ans, q1 + 1);
		dp[1] |= dp[1] << a[i];
		dp[1] |= dp[0];
		dp[0] |= dp[0] << a[i];
	}
	cout << ans << endl;
	return 0;
}