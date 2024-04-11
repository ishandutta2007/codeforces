/**
 *    author:  Mohamed Abo_Okail
 *    created: 2O/O6/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}

int main() {
	std::ios_base::sync_with_stdio(0);
	ll a, b, c; cin >> a >> b >> c;
	char ar[] = {'b', 'a', 'a', 'b', 'c', 'a', 'c'};
	int ans = 0, flag = 0, cur = 0;
	flag = min(a / 3, min(b / 2, c / 2));
	ans = flag * 7;
	a -= flag * 3;
	b -= flag * 2;
	c -= flag * 2;
	int x = a, y = b, z = c;
	for (int i = 0; i < 7; i++) {
		int indx = i, cnt = 0;
		a = x; b = y; c = z;
		while(true) {
			if(ar[indx] == 'a' && a) cnt ++, a --;
			else if(ar[indx] == 'b' && b) cnt ++, b --;
			else if(ar[indx] == 'c' && c) cnt ++, c --;
			else break;
			indx ++;
			if(indx == 7) indx = 0;
		}
		cur = max(cur, cnt);
	}
	cout << ans + cur << endl;
}