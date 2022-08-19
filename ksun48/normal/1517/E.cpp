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
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(ll& x : a) cin >> x;
	ll ans = 0;
	{
		ll z = 0;
		for(int i = 0; i < n; i++){
			z += a[i];
		}
		for(int i = n-1; i >= 0; i--){
			z -= 2*a[i];
			if(i <= n-2 && i >= 2 && z > 0){
				ans++;
			}
		}
	}
	for(int j = 0; j < 2; j++){
		ll z = 0;
		for(int i = 0; i < n; i++){
			if((i & 1) == j){
				z += a[i];
				// 0
			} else {
				z -= a[i];
				// 1
			}
		}
		vector<pair<int, ll> > ldiff;
		ldiff.push_back({0, 0});
		vector<pair<int, ll> > rdiff;
		rdiff.push_back({n, 0});
		{
			ll cd = 0;
			for(int i = 0; i < n; i++){
				if((i & 1) == j){
					cd -= 2 * a[i];
				} else {
					if(i >= 1){
						ldiff.push_back({i+1, cd});
					}
					if(i >= 2){
						ldiff.push_back({i+1, cd + 2*a[0]});
					}
				}
			}
		}
		{
			ll cd = 0;
			for(int i = n-1; i >= 0; i--){
				if((i & 1) != j){
					cd += 2 * a[i];
				} else {
					if(i <= n-2){
						rdiff.push_back({i, cd});
					}
					if(i <= n-3){
						rdiff.push_back({i, cd - 2*a[n-1]});
					}
				}
			}
		}
		for(auto& [l, lv] : ldiff){
			lv = -lv-z;
		}
		vector<ll> q;
		for(auto [l, lv] : ldiff) q.push_back(lv);
		for(auto [r, rv] : rdiff) q.push_back(rv);
		sort(q.begin(), q.end());
		auto get_idx = [&](ll r) -> int {
			return lower_bound(q.begin(), q.end(), r) - q.begin();
		};
		sort(ldiff.begin(), ldiff.end());
		sort(rdiff.begin(), rdiff.end());
		int L = q.size();
		FT ft(L);
		int idx = 0;
		for(auto [r, rv] : rdiff){
			while(idx < ldiff.size() && ldiff[idx].first <= r){
				ft.update(get_idx(ldiff[idx].second), 1);
				idx++;
			}
			ans += ft.query(get_idx(rv));
		}
	}
	ans %= 998244353;
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}