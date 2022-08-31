#include <bits/stdc++.h>
using namespace std;


void solve(){
	using ll = long long;
	ll n;
	cin >> n;
	vector<ll> a(n);
	for(ll& x : a) cin >> x;
	bool same = true;
	for(ll x : a) if(x != a[0]) same = false;
	if(same){
		cout << n << '\n';
	} else {
		cout << 1 << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}