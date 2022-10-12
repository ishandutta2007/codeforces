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
	int n; cin >> n;
	vector < int > v(n);
	int sm = 0, flag = 0, cur = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sm += v[i];
	}
	flag = sm / n;
	cur = sm % n;
	for (int i = 0; i < n; i++) {
		if(v[i] > flag) {
			if(v[i] >= flag + 1 && cur) {
				ans += v[i] - flag - 1;
				cur--;
			}
			else {
				ans += v[i] - flag;
			}
		}
	}
	cout << ans << endl;
}