#include <bits/stdc++.h>
using namespace std;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] = max(s[pos], dif);
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res = max(res, s[pos-1]);
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

struct FT2 {
	vector<vi> ys; vector<FT> ft;
	FT2(int limx) : ys(limx) {}
	void fakeUpdate(int x, int y) {
		for (; x < sz(ys); x |= x + 1) ys[x].push_back(y);
	}
	void init() {
		trav(v, ys) sort(all(v)), ft.emplace_back(sz(v));
	}
	int ind(int x, int y) {
		return (int)(lower_bound(all(ys[x]), y) - ys[x].begin()); }
	void update(int x, int y, ll dif) {
		for (; x < sz(ys); x |= x + 1)
			ft[x].update(ind(x, y), dif);
	}
	ll query(int x, int y) {
		ll sum = 0;
		for (; x; x &= x - 1)
			sum = max(sum, ft[x-1].query(ind(x-1, y)));
		return sum;
	}
};

void solve(){
	int n, m;
	cin >> n >> m;
	vector<string> _s(n);
	for(string& x : _s) cin >> x;
	int both = 0;
	for(int parity = 0; parity < 2; parity++){
		vector<string> s = _s;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(((i + j) & 1) != parity){
					s[i][j] = '0';
				}
			}
		}
		FT2 ft2(n+m+1);
		for(int j = 0; j < m; j++){
			for(int i = 0; i < n; i++){
				if(s[i][j] == '0') continue;
				ft2.fakeUpdate(j-i+n, j+i);
			}
		}
		ft2.init();
		int ans = 0;
		for(int j = 0; j < m; j++){
			for(int i = 0; i < n; i++){
				if(s[i][j] == '0') continue;
				int x = ft2.query(j-i+n, j+i) + 1;
				ans = max(x, ans);
				ft2.update(j-i+n, j+i, x);
			}
		}
		both += ans;
	}
	cout << both << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}