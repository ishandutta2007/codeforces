#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void ans(ll x){
	x = max(x + 7, x * 2);
	cout << "! " << x << '\n';
	cout << flush;
}

ll query(ll q){
	cout << "? " << q << '\n';
	cout << flush;
	ll res;
	cin >> res;
	return res;
}

void solve(){
	vector<ll> g;
	for(ll p = 2; p <= 700; p++){
		bool pr = true;
		for(ll a = 2; a * a <= p; a++){
			if(p % a == 0){
				pr = false;
				break;
			}
		}
		if(!pr) continue;
		ll q = p;
		while(q * p <= 3000) q *= p;
		g.push_back(q);
	}
	ll cnt = 1;
	ll cur = 1;
	ll M = ll(1e18);
	ll n = 1;
	vector<ll> queries;
	for(ll a : g){
		if(cur > M / a){
			queries.push_back(cur);
			cnt++;
			cur = 1;
		}
		cur *= a;
	}
	queries.push_back(cur);
	for(ll q : queries){
		n *= query(q);
	}
	ll nd = 0;
	for(ll p = 1; p * p <= n; p++){
		if(n % p == 0){
			nd += 1;
			if(n != p * p) nd += 1;
		}
	}
	ans(nd);
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}