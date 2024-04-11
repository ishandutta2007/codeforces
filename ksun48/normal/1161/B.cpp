#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;


vi pi(const vi& s) {
	vi p(sz(s));
	rep(i,1,sz(s)) {
		ll g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}


int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
	int n, m;
	cin >> n >> m;
	vector<ll> stuff(n);
	for(int i = 0; i < n; i++){
		stuff[i] = rng() & ((1ll << 62) - 1);
	}
	vector<ll> what(n);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		what[a] ^= stuff[(b-a+n) % n];
		what[b] ^= stuff[(a-b+n) % n];
	}

	vector<ll> q;
	for(ll x : what) q.push_back(x);
	for(ll x : what) q.push_back(x);
	q.pop_back();
	vector<ll> ret = pi(q);
	int works = 0;
	for(ll x : ret){
		if(x >= n) works = 1;
	}
	if(works){
		cout << "Yes" << '\n';
	} else {
		cout << "No" << '\n';
	}
}