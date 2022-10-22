#include <bits/stdc++.h>
#define broken cerr << "running on " << __FUNCTION__ <<" "<< __LINE__ << endl
#define x first
#define y second
#define sz(a) int((a).size())
#define ll long long
#define ull unsigned long long
using namespace std;
const int N = 1e6 + 10;
int n, e, a[N], vis[N], p[N], tot = 0;
int buc[N], pre[N], suf[N];
void sieve(int n) {
	vis[0] = vis[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) p[++tot] = i;
		for(int j = 1; j <= tot && p[j] * i <= n; j++) {
			vis[p[j] * i] = 1;
			if(i % p[j] == 0) break;
		}
	}
	return;
}
void solve() {
	cin >> n >> e;
	for(int i = 1; i <= n; i++) cin >> a[i];
	ll ans = 0;
	for(int i = 1; i <= e; i++) {
		int tot = 0;
		for(int j = i; j <= n; j += e) {
			buc[++tot] = a[j];
		}
		for(int j = 1; j <= tot; j++) {
			pre[j] = pre[j - 1];
			if(buc[j] > 1) pre[j] = j;
		}
		suf[tot + 1] = tot + 1;
		for(int j = tot; j >= 1; j--) {
			suf[j] = suf[j + 1];
			if(buc[j] > 1) suf[j] = j;
		}
		for(int j = 1; j <= tot; j++) {
			if(!vis[buc[j]]) {
				int l = j - pre[j - 1];
				int r = suf[j + 1] - j;
				ans += 1ll * l * r - 1;
			}
		}
	}
	cout << ans << endl;
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	sieve(N - 10);
	int t;
	// solve();
	for(cin >> t; t--; solve());
	return 0;
}