#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(ll& x : a) cin >> x;
	sort(a.begin(), a.end());
	ll mp = -2e18;
	for(int i = 0; i <= 5; i++){
		ll prod = 1;
		for(int j = 0; j < i; j++) prod *= a[j];
		for(int j = i; j < 5; j++) prod *= a[n-5+j];
		mp = max(mp, prod);
	}
	cout << mp << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}