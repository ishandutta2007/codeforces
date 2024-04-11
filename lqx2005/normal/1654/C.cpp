#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define x first
#define y second
typedef long long ll;
typedef unsigned long long ull;
map<ll, int> cnt;
int dfs(ll x) {
	if(cnt[x]) return cnt[x]--, 1;
	if(x == 1) return 0;
	if(dfs(x / 2) && dfs((x + 1) / 2)) return 1;
	return 0;
}
void solve() {
	cnt.clear();
	int n;
	cin >> n;
	ll s = 0;
	for(int i = 1, x; i <= n; i++) {
		cin >> x;
		s += x;
		cnt[x]++;
	}
	if(dfs(s)) cout << "YES" << endl;
	else cout << "NO" << endl;
	return;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	for(cin >> t; t--; ) {
		solve();
	}
    return 0;
}