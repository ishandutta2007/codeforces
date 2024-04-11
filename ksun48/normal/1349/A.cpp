#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	auto lcm = [&](ll x, ll y) -> ll {
		return x * y / __gcd(x, y);
	};
	ll g = 0;
	ll pg = 0;
	for(ll x : a){
		g = __gcd(g, lcm(pg, x));
		pg = __gcd(pg, x);
	}
	cout << g << '\n';
}