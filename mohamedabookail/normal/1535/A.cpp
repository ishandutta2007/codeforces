/**
*    author:  Mohamed Abo Okail
*    created: O4/O6/2O21
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
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << (max(a, b) > min(c, d) && max(c, d) > min(a, b) ? "YES" : "NO") << endl;
	}
}