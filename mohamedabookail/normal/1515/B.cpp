/**
*    author:  Mohamed Abo Okail
*    created: 18/O5/2O21
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
		int n; cin >> n;
		if(n % 2 == 0) {
			n /= 2;
			ll cur = (sqrt(n) + 0.5);
			if(cur * cur == n) {
				cout << "YES" << endl;
				continue;
			}
			n *= 2;
		}
		if(n % 4 == 0) {
			n /= 4;
			ll cur = (sqrt(n) + 0.5);
			if(cur * cur == n) {
				cout << "YES" << endl;
				continue;
			}
		}
		cout << "NO" << endl;
	}
}