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


int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = n-1; i >= 1; i--) a[i] -= a[i-1];

	ll ans = 0;

	for(int i = 1; i < n; i++) if(a[i] >= 0) ans += a[i];
	int Q;
	cin >> Q;
	for(int i = 0; i <= Q; i++){
		ll val = a[0];
		val += ans;
		if(val & 1) val += 1;
		cout << (val / 2) << '\n';
		if(i == Q) break;
		int l, r;
		ll x;
		cin >> l >> r >> x;
		l--; r--;
		if(r+1 < n){
			if(a[r+1] >= 0) ans -= a[r+1];
			a[r+1] -= x;
			if(a[r+1] >= 0) ans += a[r+1];
		}
		{
			if(l > 0 && a[l] >= 0) ans -= a[l];
			a[l] += x;
			if(l > 0 && a[l] >= 0) ans += a[l];
		}
	}
}