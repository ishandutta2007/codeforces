#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, P = 998244353;
int n, x[N], y[N], s[N];
int cnt[N], sum[N];
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i] >> s[i];
	}
	x[0] = 0;
	for(int i = 1; i <= n; i++) {
		int p = lower_bound(x + 1, x + n + 1, y[i]) - x;
		cnt[i] = (sum[i - 1] - sum[p - 1] + P) % P;
		cnt[i] = (cnt[i] + (x[i] - y[i]) % P) % P;
		sum[i] = (sum[i - 1] + cnt[i]) % P;
	}
	int ans = (x[n] + 1) % P;
	for(int i = 1; i <= n; i++) {
		if(s[i]) {
			ans = (ans + cnt[i]) % P;
		}
	}
	cout << ans << endl;
    return 0;
}