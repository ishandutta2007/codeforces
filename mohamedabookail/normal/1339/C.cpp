/**
 *    author:  Mohamed Abo_Okail
 *    created: 16/O4/2O2O
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
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector < ll > v(n);
		ll cnt = 0, mx = -1;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		for (int i = 1; i < n; i++) {
			if(v[i] < v[i - 1]) {
				ll mn = v[i], inx = 0;
				for (int j = i; j < n; j++) {
					if(v[j] < v[i - 1]) mn = min(mn, v[j]);
					else break;
					inx = j;
				}
				mx = max(mx, v[i - 1] - mn);
				i = inx;
			}
		}
		ll sm = 0;
		while(sm < mx) {
			cnt++;
			sm += pow(2, cnt - 1);
		}
		cout << cnt << o_o;
	}
}