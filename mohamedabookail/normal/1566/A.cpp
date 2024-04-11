/**
*    author:  Mohamed Abo Okail
*    created: 13/O9/2O21
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
		ll n, s; cin >> n >> s;
		ll a = (n + 1) / 2 - 1;
		ll b = n - a;
		cout << s / b << endl;
	}
}