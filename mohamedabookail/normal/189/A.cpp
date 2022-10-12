/**
*    author:  Mohamed Abo_Okail
*    created: 14/O9/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
int main() {
	std::ios_base::sync_with_stdio(0);
	ll n, a, b, c; cin >> n >> a >> b >> c;
	ll mx = 0;
	for (ll i = 0; i <= n; i++) {
		for (ll j = 0; j <= n; j++) {
			if(a * i + b * j <= n) {
				ll flag = a * i + b * j;
				flag = n - flag;
				if(flag % c == 0) {
					mx = max(mx, i + j + flag / c);
				}
			}
		}
	}
	cout << mx << endl;
}