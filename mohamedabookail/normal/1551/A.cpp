/**
*    author:  Mohamed Abo Okail
*    created: 23/O7/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";
 
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		ll a = n / 3 + (n % 3 != 0);
		ll b = n / 3;
		if(n % 3 == 2) swap(a, b);
		cout << a << ' ' << b << endl;
	}
}