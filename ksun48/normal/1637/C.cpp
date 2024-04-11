#include <bits/stdc++.h>
using namespace std;

void solve(){
	using ll = int64_t;
	int n;
	cin >> n;
	vector<ll> a(n);
	for(ll& x : a){
		cin >> x;
	}
	a.erase(a.begin());
	a.erase(prev(a.end()));
	n = (int)a.size();
	if(n == 1){
		if(a[0] % 2){
			cout << -1 << '\n';
		} else {
			cout << (a[0] / 2) << '\n';
		}
		return;
	}
	if(a == vector<ll>(n, 1)){
		cout << -1 << '\n';
		return;
	}
	ll steps = 0;
	for(ll x : a){
		steps += (x + 1) / 2;
	}
	cout << steps << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}