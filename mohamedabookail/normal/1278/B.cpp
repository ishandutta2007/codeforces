/**
 *    author:  Mohamed Abo_Okail
 *    created: O7/O6/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
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
		ll a, b; cin >> a >> b;
		ll flag = abs(a - b);
		ll cur = 0, cnt = 0;
		while(true) {
			if((flag & 1) && cur >= flag && (cur & 1)) break;
			if(!(flag & 1) && cur >= flag && !(cur & 1)) break;
			cnt++; cur = (cnt * (cnt + 1)) / 2;
		}
		cout << cnt << endl;
	}
}