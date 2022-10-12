/**
 *    author:  Mohamed Abo_Okail
 *    created: O8/O3/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define o_o "\n"
#define ll long long
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}
 
int main()
{
	std::ios_base::sync_with_stdio(0);
	ll n, m, k; cin >> n >> m >> k;
	vector < ll > a(n), b(m), v;
	map < ll, ll > mpA, mpB;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	for (int i = 1; i * i <= k; i++) {
		if(!(k % i)) {
			v.push_back(i);
			if(i != k / i) v.push_back(k / i);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		ll cnt = 0, f = 0;
		for (int j = 0; j < n; j++) {
			if(a[j]) cnt++;
			else cnt = 0;
			if(cnt >= v[i]) f++;
		}
		mpA[v[i]] = f;
	}
	for (int i = 0; i < v.size(); i++) {
		ll cnt = 0, f = 0;
		for (int j = 0; j < m; j++) {
			if(b[j]) cnt++;
			else cnt = 0;
			if(cnt >= v[i]) f++;
		}
		mpB[v[i]] = f;
	}
	for (int i = 0; i < v.size(); i++) {
		if(v[i] * v[i] == sqrt(k) * sqrt(k)) {
			ans += mpA[v[i]] * mpB[v[i]];
			mpA[v[i]] = 0;
		}
		else {
			ans += mpA[v[i]] * mpB[k / v[i]];
			mpB[k / v[i]] = 0;
		}
	}
	cout << ans << o_o;
}