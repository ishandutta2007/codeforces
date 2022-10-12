/**
*    author:  Mohamed Abo Okail
*    created: 25/11/2O21
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
		ll a, b; cin >> a >> b;
		cout << min(a, min(b, (a + b) / 4)) << endl;
	}
}