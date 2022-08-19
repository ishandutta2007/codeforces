#include <bits/stdc++.h>
using namespace std;

#define wssert(x) if(!(x)) { exit(0); }

const bool TEST = false;

using ll = long long;

const ll MAXX = ll(1e18);

int n;
ll l;

ll D;

int nq = 0;

map<pair<int, ll>, ll> cache;

ll f(int i, ll x){
	if(cache.count({i, x})) return cache[{i, x}];
	nq += 1;
	assert(nq <= 29999);
	if(TEST) return min(x / (i+1), 5ll);
	assert(0 <= i && i < n);
	assert(0 <= x && x <= MAXX);
	cout << "?" << " " << i + 1 << " " << x << '\n';
	cout << flush;
	ll val;
	cin >> val;
	cache[{i, x}] = val;
	return val;
}

vector<pair<ll,ll> > ans;

mt19937 mt(48);

void solve(ll s, ll e, vector<int> ids){
	int n = ids.size();
	if(n == 1){
		ans[ids.front()] = {s, e};
		return;
	}

	int z = n / 2;

	vector<int> lids;
	vector<int> rids;

	while(!ids.empty()){
		shuffle(ids.begin(), ids.end(), mt);
		int x = ids.front();

		ll l = s - 1;
		ll r = e + 1;

		ll loc = -1;
		assert(f(x, e) - f(x, s) >= n * D);
		while(l + 1 < r){
			ll m = (l + r) / 2;
			bool lok = f(x, m) - f(x, s) >= z * D;
			bool rok = f(x, e) - f(x, m) >= (n - z) * D;
			if(lok && rok){
				loc = m;
				break;
			} else if(rok){
				l = m;
			} else if(lok){
				r = m;
			} else assert(false);
		}
		assert(loc != -1);

		vector<int> lt, eq, rt;
		for(int x : ids){
			assert(f(x, e) - f(x, s) >= n * D);
			bool lok = f(x, loc) - f(x, s) >= z * D;
			bool rok = f(x, e) - f(x, loc) >= (n - z) * D;
			if(lok && rok){
				eq.push_back(x);
			} else if(lok){
				lt.push_back(x);
			} else if(rok){
				rt.push_back(x);
			} else assert(false);
		}
		ids.clear();
		if(lids.size() + lt.size() <= z){
			for(int x : lt) lids.push_back(x);
			lt.clear();
			while(!eq.empty() && (int)lids.size() < z){
				lids.push_back(eq.back());
				eq.pop_back();
			}
		}
		if(rids.size() + rt.size() <= n-z){
			for(int x : rt) rids.push_back(x);
			rt.clear();
			while(!eq.empty() && (int)rids.size() < n-z){
				rids.push_back(eq.back());
				eq.pop_back();
			}
		}
		for(int x : lt) ids.push_back(x);
		for(int x : eq) ids.push_back(x);
		for(int x : rt) ids.push_back(x);
		if(ids.empty()){
			solve(s, loc, lids);
			solve(loc, e, rids);
			return;
		}
	}

	assert(false);
	return;
}

void answer(){
	cout << "!" << '\n';
	for(pair<ll,ll> x : ans){
		assert(x.first != -1 && x.second != -1);
		cout << x.first << ' ' << x.second << '\n';
	}
	cout << flush;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> l;
	D = l / n;

	ans.assign(n, {-1, -1});

	vector<int> ids;
	for(int i = 0; i < n; i++) ids.push_back(i);

	solve(0, MAXX, ids);
	answer();
}