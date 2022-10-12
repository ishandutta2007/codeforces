/**
*    author:  Mohamed Abo Okail
*    created: 29/O4/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n"

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while(t--) {
		ll a, b, c; cin >> a >> b >> c;
		if(a < b) swap(a, b);
		cout << ((a / b + (a % b != 0)) - 1 <= c ? "YES" : "NO") << endl;
	}
}