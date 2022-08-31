#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll MAXN = 100100;

ll work[MAXN];
ll pwork[MAXN];

vector<ll> make(vector<ll> l, vector<ll> u, ll total){
	assert(l.size() == u.size());
	ll ls = 0;
	ll us = 0;
	for(ll a : l) ls += a;
	for(ll a : u) us += a;
	if(total < ls || total > us) return {};
	for(ll i = 0; i < MAXN; i++) work[i] = 0;
	for(ll a : l) work[a]++;
	for(ll b : u) work[b]--;
	ll cur = 0;
	for(ll a : l) cur += a;
	ll s = 0;

	ll psum = 0;
	while(true){
		psum += work[s];
		if(cur <= total && total <= cur + psum){
			break;
		}
		cur += psum;
		s++;
	}
	vector<ll> ret(l.size());
	ll extra = total - cur;
	for(ll i = 0; i < (ll)ret.size(); i++){
		if(extra && l[i] <= s && s + 1 <= u[i]){
			ret[i] = s + 1;
			extra--;
		} else if(l[i] <= s && s <= u[i]){
			ret[i] = s;
		} else if(s < l[i]){
			ret[i] = l[i];
		} else {
			ret[i] = u[i];
		}
		total -= ret[i];
	}
	assert(total == 0);
	return ret;
}

vector<ll> set_make(vector<ll> l, vector<ll> u, ll cnt, ll val, ll total){
	for(ll j = 0; j < cnt; j++) l[j] = max(l[j], val);
	for(ll& x : u) x = min(x, val);
	for(ll j = 0; j < (ll)l.size(); j++) if(u[j] < l[j]) return {};
	vector<ll> res = make(l, u, total);
	return res;
}

bool okay(vector<ll> a, vector<ll> b){
	if(a.empty()) return false;
	sort(b.begin(), b.end());
	ll n = (ll)a.size();
	ll m = (ll)b.size();
	ll asum = 0;
	ll j = 0;
	ll bsum = 0;
	for(ll i = 1; i <= n; i++){
		asum += a[i-1];
		while(j < m && b[j] <= i){
			bsum += b[j];
			j++;
		}
		if(asum > bsum + (m - j) * i) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<ll> l(n), u(n);
	for(ll i = 0; i < n; i++) cin >> l[i] >> u[i];
	vector<ll> lb(m, 0);
	vector<ll> ub(m, n);
	ll q;
	cin >> q;
	for(ll i = 0; i < q; i++){
		ll p, s;
		cin >> p >> s;
		p--;
		lb[p] = s;
		ub[p] = s;
	}
	for(ll i = 1; i < m; i++) ub[i] = min(ub[i], ub[i-1]);
	for(ll i = m-2; i >= 0; i--) lb[i] = max(lb[i], lb[i+1]);
	ll s = 0; // yes
	ll e = m+1; // no

	// n problems
	// m people
	ll TOTAL;
	cin >> TOTAL;

	vector<ll> probs = make(l, u, TOTAL);
	vector<ll> people = make(lb, ub, TOTAL);
	if(probs.empty() || people.empty()){
		cout << -1 << ' ' << -1 << '\n';
		return 0;
	}

	while(s + 1 < e){
		ll mid = (s + e) / 2;

		ll maxcnt = mid;
		vector<ll> res = set_make(lb, ub, maxcnt, people[0], TOTAL);
		if(okay(res, probs)){
			s = mid;
		} else {
			e = mid;
		}
	}
	if(s == 0){
		cout << -1 << ' ' << -1 << '\n';
		return 0;
	}

	ll cnt = s;
	ll sv = people[0] - 1;
	ll ev = n + 1;
	while(sv + 1 < ev){
		ll mv = (sv + ev) / 2;
		vector<ll> res = set_make(lb, ub, cnt, mv, TOTAL);
		if(okay(res, probs)){
			sv = mv;
		} else {
			ev = mv;
		}
	}
	assert(sv >= people[0]);
	cout << cnt << ' ' << sv << '\n';
}