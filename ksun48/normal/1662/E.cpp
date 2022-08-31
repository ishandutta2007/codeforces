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
	vector<int> p(n);
	for(int& x : p){
		cin >> x;
		x--;
	}
	vector<int> loc(n);
	for(int i = 0; i < n; i++){
		loc[p[i]] = i;
	}
	vector<vector<int> > runs;
	vector<int> cur;
	for(int i = 0; i < n; i++){
		if(cur.empty() || loc[i] > loc[cur.back()]){
			cur.push_back(i);
		} else {
			runs.push_back(cur);
			cur = {i};
		}
	}
	if(!cur.empty()) runs.push_back(cur);
	ll ans = 0;
	int k = (int)runs.size();

	ll c = 0;
	ll d = 0;
	for(int i = 0; i < k; i++){
		ans += d * ll(runs[i].size());
		d += c;
		c += ll(runs[i].size());
	}
	reverse(runs.begin(), runs.end());
	vector<int> seq;
	for(vector<int> v : runs){
		seq.insert(seq.end(), v.begin(), v.end());
	}
	vector<int> sp(n);
	for(int i = 0; i < n; i++){
		sp[i] = loc[seq[i]];
	}
	FT ft(n);
	for(int i = 0; i < n; i++){
		ans += ft.query(n) - ft.query(sp[i]);
		ft.update(sp[i], 1);
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}