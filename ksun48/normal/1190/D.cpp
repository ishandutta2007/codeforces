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
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int,int> > a(n);
	set<int> r;
	for(int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second;
		a[i].second *= -1;
		r.insert(a[i].first);
		r.insert(a[i].second);
	}
	map<int,int> l;
	for(int x : r){
		int v = l.size();
		l[x] = v;
	}
	for(int i = 0; i < n; i++){
		a[i].first = l[a[i].first];
		a[i].second = l[a[i].second];
	}

	int z = l.size();
	FT ft(z+2);

	vector<vector<int> > where(z);
	vector<int> has(z, 0);
	for(int i = 0; i < n; i++){
		where[a[i].second].push_back(a[i].first);
	}
	ll ans = 0;
	for(int i = 0; i < z; i++){
		vector<int> v = where[i];
		if(v.empty()) continue;
		sort(v.begin(), v.end());

		for(int x : v){
			if(!has[x]){
				has[x] = 1;
				ft.update(x, 1);
			}
		}

		for(int i = 0; i <= v.size(); i++){
			int l = (i == 0) ? -1 : v[i-1];
			int r = (i == (int)v.size()) ? z+1 : v[i];

			if(l < r){
				ll cur = ft.query(r) - ft.query(l+1);
				ans -= cur * (cur + 1) / 2;
			}
		}

		ll tot = ft.query(z+1);
		ans += tot * (tot + 1) / 2;
	}
	cout << ans << '\n';
}