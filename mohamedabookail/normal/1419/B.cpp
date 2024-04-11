/**
*    author:  Mohamed Abo_Okail
*    created: 19/O9/2O2O
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
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		vector < ll > a;
		a.push_back(1);
		a.push_back(3);
		a.push_back(7);
		ll flag = 8;
		for (int i = 0; i < 50; i++) {
			a.push_back(a.back() + flag);
			flag *= 2;
		}
		ll ans = 0;
		for (int i = 0; i < sz(a); i++) {
			if(n >= a[i] * (a[i] + 1) / 2) {
				n -= (a[i] * (a[i] + 1) / 2);
				ans++;
			}
			else break;
		}
		cout << ans << endl;
	}
}