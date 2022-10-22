#include <bits/stdc++.h>
#define broken cerr << "running on " << __FUNCTION__ <<" "<< __LINE__ << endl
#define x first
#define y second
#define sz(a) int((a).size())
#define ll long long
#define ull unsigned long long
using namespace std;
const int N = 1e6 + 10;
int n, p[N];
ll a[N];
int stk1[N], stk2[N], top1, top2;
int cnt[N][60];
int query(int x, int y) {
	int t = lower_bound(stk1 + 1, stk1 + top1 + 1, x) - stk1;
	if(t == top1 + 1) return cnt[t - 1][y];
	return cnt[t - 1][y] + (p[stk1[t]] == y) * (x - stk1[t - 1]);
}
void solve() {
	cin >> n;
	ll ans = 0;
	for(int i = 1; i <= n; i++) cin >> a[i], p[i] = __builtin_popcountll(a[i]);
	for(int i = 1; i <= n; i++) {
		while(top2 && a[stk2[top2]] >= a[i]) {
			ans -= 1ll * (query(stk2[top2], p[stk2[top2]]) - query(stk2[top2 - 1], p[stk2[top2]])) * (n - i + 1);
			top2--;
		}
		stk2[++top2] = i;
		ans += 1ll * (query(i, p[i]) - query(stk2[top2 - 1], p[i])) * (n - i + 1);
		while(top1 && a[stk1[top1]] <= a[i]) {
			top1--;
		}
		stk1[++top1] = i;
		for(int j = 0; j < 60; j++) cnt[top1][j] = cnt[top1 - 1][j];
		cnt[top1][p[i]] += i - stk1[top1 - 1];
	}
	top1 = top2 = 0;
	for(int i = 1; i <= n; i++) {
		while(top1 && a[stk1[top1]] >= a[i]) {
			top1--;
		}
		stk1[++top1] = i;
		for(int j = 0; j < 60; j++) cnt[top1][j] = cnt[top1 - 1][j];
		cnt[top1][p[i]] += i - stk1[top1 - 1];
		while(top2 && a[stk2[top2]] <= a[i]) {
			ans -= 1ll * (query(stk2[top2], p[stk2[top2]]) - query(stk2[top2 - 1], p[stk2[top2]])) * (n - i + 1);
			top2--;
		}
		stk2[++top2] = i;
		ans += 1ll * (query(i, p[i]) - query(stk2[top2 - 1], p[i])) * (n - i + 1);
	}
	cout << ans << endl;
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	solve();
	// for(cin >> t; t--; solve());
	return 0;
}