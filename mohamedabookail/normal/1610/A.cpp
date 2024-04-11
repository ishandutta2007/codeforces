/**
*    author:  Mohamed Abo Okail
*    created: 22/11/2O21
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
		ll n, m; cin >> n >> m;
		if(n == 1 && m == 1) {
			cout << 0 << endl;
		}
		else {
			cout << (min(n, m) == 1 ? 1 : 2) << endl;
		}
	}
}