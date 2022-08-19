#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	ll sum = 0;
	ll x = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		x ^= a[i];
		sum += a[i];
	}
	cout << 2 << '\n';
	cout << x << ' ' << x + sum << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}