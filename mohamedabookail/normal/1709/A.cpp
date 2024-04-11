/**
*    author:  Mohamed Abo Okail
*    created: 21/O7/2O22
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
	
	ll t; cin >> t;
	while(t--) {
		int x;
		cin >> x;
		int ar[3];
		cin >> ar[0] >> ar[1] >> ar[2];
		map < int, bool > mp;
		mp[x] = 1;
		mp[ar[x - 1]] = 1;
		x = ar[x - 1];
		mp[ar[x - 1]] = 1;
		if(mp[1] && mp[2] && mp[3]) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}