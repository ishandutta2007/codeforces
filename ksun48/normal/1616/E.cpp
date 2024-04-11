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
	string s, t;
	cin >> s >> t;

	ll M = 1e15;
	ll ans = M;
	FT ft(n+1);
	vector<vector<int> > cw(26);
	for(int i = 0; i < n; i++){
		cw[s[i]-'a'].push_back(i);
		ft.update(i, 1);
	}
	vector<int> ci(26, 0);
	ll cans = 0;
	for(int i = 0; i < n; i++){
		int x = t[i] - 'a';
		int next_less = n;
		for(int c = 0; c < x; c++){
			if(ci[c] < cw[c].size()){
				next_less = min(next_less, cw[c][ci[c]]);
			}
		}
		if(next_less < n){
			ans = min(ans, cans + ft.query(next_less));
		}
		if(ci[x] >= cw[x].size()) break;
		int nextc = cw[x][ci[x]];
		ci[x]++;
		cans += ft.query(nextc);
		ft.update(nextc, -1);
	}
	if(ans >= M){
		ans = -1;
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}