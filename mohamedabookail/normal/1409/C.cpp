/**
*    author:  Mohamed Abo_Okail
*    created: O4/O9/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return (x / _gcd(x, y) * y);
}
 
int main() {
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		ll n, x, y; cin >> n >> x >> y;
		if(n == 2) {
			cout << x << ' ' << y <<  endl;
			continue;
		}
		ll flag = y - x, ans = 0;
		for (int i = n - 1; i > 1 ; i--) {
			if(flag % i == 0) {
				ans = i;
				break;
			}
		}
		if(!ans) {
			deque < ll > dq;
			dq.push_back(x);
			dq.push_back(y);
			n -= 2;
			ans = y - x;
			for (int i = x - ans; i > 0 ; i -= ans) {
				if(!n) break;
				dq.push_front(i);
				n--;
			}
			while(n--) {
				dq.push_back(y + ans);
				y += ans;
			}
			for (int i = 0; i < sz(dq); i++) {
				cout << dq[i] << ' ';
			}
			cout << endl;
			continue;
		}
		ans = flag / ans;
		deque < ll > dq;
		dq.push_back(x);
		for (int i = x + ans; i <= y; i += ans) {
			dq.push_back(i);
		}
		n -= sz(dq);
		for (int i = x - ans; i > 0 ; i -= ans) {
			if(!n) break;
			dq.push_front(i);
			n--;
		}
		while(n--) {
			dq.push_back(y + ans);
			y += ans;
		}
		for (int i = 0; i < sz(dq); i++) {
			cout << dq[i] << ' ';
		}
		cout << endl;
	}
}