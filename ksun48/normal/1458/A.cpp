#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	using ll = long long;
	vector<ll> a(n), b(m);
	for(ll& x : a) cin >> x;
	for(ll& x : b) cin >> x;
	ll ga = 0;
	for(ll x : a){
		ga = gcd(ga, abs(x - a[0]));
	}
	for(ll x : b){
		cout << gcd(ga, x + a[0]) << ' ';
	}
	cout << '\n';
}