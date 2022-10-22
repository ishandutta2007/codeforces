#include <bits/stdc++.h>
#define i64 long long
using namespace std;
const int N = 2e5 + 10, P = 998244353;
int rev[N], b[N], vis[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	for(cin >> T; T--; ) {
		int n, k;
		cin >> n >> k;
		for(int i = 1; i <= n; i++) vis[i] = 0;
		vis[0] = vis[n + 1] = 1;
		for(int i = 1, x; i <= n; i++) cin >> x, rev[x] = i;
		for(int i = 1; i <= k; i++) cin >> b[i], vis[rev[b[i]]] = 1;
		int cnt = 0, one = 0, zero = 0;
		for(int i = 1; i <= n; i++) {
			if(vis[i] == 0) {
				cnt += one && zero;
				one = 0;
				zero = 1;
			} else {
				one = 1;
			}
		}
		int ans = 1;
		while(cnt--) (ans <<= 1) %= P;
		for(int i = 1; i <= k; i++) {
			int p = rev[b[i]];
			if(vis[p - 1] && vis[p + 1]) {
				ans = 0;
				break;
			}
			vis[p] = 0;
		}
		cout << ans << endl;
	}
	return 0;
}