#include <bits/stdc++.h>
using namespace std;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct FT {
	vector<ll> s;
	FT(int n) : s(n, -1e9) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] = max(s[pos], dif);
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = -1e9;
		for (; pos > 0; pos &= pos - 1) res = max(res, s[pos-1]);
		return res;
	}
};

void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(ll& x : a) cin >> x;
	vector<ll> psum(n+1, 0);
	for(int i = 0; i < n; i++){
		psum[i+1] = psum[i] + a[i];
	}

	vector<ll> l = psum;
	sort(l.begin(), l.end());

	auto get_idx = [&](ll r) -> int {
		int x = lower_bound(l.begin(), l.end(), r) - l.begin();
		return x;
	};

	FT ftl(n+2);
	vector<ll> dpeq(n+1, -1e9);
	vector<ll> dp(n+1, -1e9);
	dp[0] = 0;
	ftl.update(get_idx(0), dp[0]);
	dpeq[get_idx(0)] = dp[0];
	for(int i = 1; i <= n; i++){
		int x = get_idx(psum[i]);
		dp[i] = max(dp[i], 2 * i + ftl.query(x));
		dp[i] = max(dp[i], i + dpeq[x]);
		dp[i] = max(dp[i], dp[i-1]);
		ftl.update(x, dp[i] - 2 * i);
		dpeq[x] = max(dpeq[x], dp[i] - i);
	}
	cout << (dp[n] - n) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}