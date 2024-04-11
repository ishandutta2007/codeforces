#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define par pair<int, int>
#define pb push_back
#define eb emplace_back
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
const int N = 2e5 + 10, P = 1e9 + 7;
int n;
struct fenw {
	int t[N];
	void clear() { for(int i = 0; i <= n; i++) t[i] = 0; }
	void add(int x, int v) { for(int i = x; i <= n; i += i & (-i)) (t[i] += v) %= P; }
	int sum(int x) { int res = 0; for(int i = x; i > 0; i -= i & (-i)) (res += t[i]) %= P; return res;}
}p, e;
int dp1[N], dp2[N], a[N], arr[N], atot = 0;
int pos[N], tot = 0;
vector<int> s[N];
void solve() {
	atot = tot = 0;
	cin >> n;
	p.clear(), e.clear();
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		arr[++atot] = a[i];
	}
	sort(arr + 1, arr + atot + 1);
	atot = unique(arr + 1, arr + atot + 1) - (arr + 1);
	for(int i = 1; i <= atot; i++) s[i].clear();
	for(int i = 1; i <= n; i++) a[i] = lower_bound(arr + 1, arr + atot + 1, a[i]) - arr;
	for(int i = 1; i <= n; i++) s[a[i]].push_back(i);
	for(int i = n; i >= 1; i--) if(tot == 0 || a[pos[tot]] <= a[i]) pos[++tot] = i;
	for(int i = 1; i <= n; i++) {
		dp1[i] = (p.sum(a[i] - 1) + 1) % P, dp2[i] = (e.sum(a[i] - 1) + dp1[i]) % P;
		p.add(a[i], dp1[i]), e.add(a[i], dp2[i]);
		// cout << dp1[i] <<" " << dp2[i] << endl;
	}
	p.clear(), e.clear();
	int ans = 0;
	for(int i = 1; i <= n; i++) (ans += dp2[i]) %= P;
	for(int i = 1; i <= tot; i++) {
		int x = pos[i];
		(ans += P - dp2[x]) %= P;
		vector<int> now;
		for(int j = a[pos[i - 1]]; j < a[pos[i]]; j++) for(int x : s[j]) now.push_back(x);
		now.push_back(x);
		sort(now.begin(), now.end());
		for(int x : now) {
			dp1[x] = (e.sum(x) + p.sum(a[x] - 1)) % P;
			p.add(a[x], dp1[x]);
		}
		(ans += dp1[x]) %= P;
		for(int x : now) p.add(a[x], (P - dp1[x]) % P);
		for(int j = a[pos[i - 1]]; j < a[pos[i]]; j++) for(int x : s[j]) e.add(x, dp2[x]);
	}
	cout << ans << endl;
    return;
}
int main() {
    int t;
    for(cin >> t; t--; solve());
	return 0;
}