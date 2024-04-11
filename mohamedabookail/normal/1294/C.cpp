/**
 *    author:  Mohamed Abo_Okail
 *    created: 22/O1/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define ll long long
#define endl "\n"
 
int main() 
{
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		ll a = 0, b = 0, ans = n;
		for (int i = 2; (i * i) <= n; i++) {
			if(!(n % i)) {
				a = i;
				break;
			}
		}
		if(!a) {
			cout << "NO" << endl;
			continue;
		}
		n /= a;
		for (int i = 2; (i * i) <= n; i++) {
			if(i == a) { continue; }
			if(!(n % i)) {
				b = i;
				break;
			}
		}
		if(!b) {
			cout << "NO" << endl;
			continue;
		}
		n /= b;
		if(a * b * n == ans && b != n) {
			cout << "YES" << endl;
			cout << a << ' ' << b << ' ' << n << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}