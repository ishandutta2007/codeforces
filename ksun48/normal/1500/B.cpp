#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}

ll crt(ll a, ll m, ll b, ll n) {
	if (n > m) swap(a, b), swap(m, n);
	ll x, y, g = euclid(m, n, x, y);
	assert((a - b) % g == 0); // else no solution
	x = (b - a) % n * x % n / g * m + a;
	return x < 0 ? x + m*n/g : x;
}


int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	ll n, m, k;
	cin >> n >> m >> k;
	ll lcm = n / gcd(n, m) * m;
	vector<int> a(n), b(m);
	for(int& x : a) cin >> x;
	for(int& x : b) cin >> x;
	map<int,int> as, bs;
	for(int i = 0; i < n; i++) as[a[i]] = i;
	for(int i = 0; i < m; i++) bs[b[i]] = i;
	ll s = 0;
	ll e = 1e18;
	vector<ll> res;
	for(int i = 0; i < n; i++){
		if(!bs.count(a[i])) continue;
		int j = bs[a[i]];
		// i mod n
		// j mod m
		ll g = gcd(n, m);
		if(i % g != j % g) continue;
		ll v = crt(i, n, j, m);
		v %= lcm;
		if(v < 0) v += lcm;
		res.push_back(v);
	}

	while(s + 1 < e){
		ll mid = (s + e) / 2;
		ll annoy = mid;
		ll whole = mid / lcm;
		ll part = mid % lcm;
		for(ll x : res){
			annoy -= whole;
			if(x < part) annoy -= 1;
		}
		if(annoy >= k){
			e = mid;
		} else {
			s = mid;
		}
	}
	cout << e << '\n';
}