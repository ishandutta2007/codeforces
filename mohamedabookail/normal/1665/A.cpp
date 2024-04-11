/**
*    author:  Mohamed Abo Okail
*    created: O8/O4/2O22
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
 
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		if(n % 4 == 0) {
			cout << n / 4 << ' ' << n / 4 << ' ' << n / 4 << ' ' << n / 4 << endl;
		}
		else {
			cout << n - 3 << " 1 1 1" << endl;
		}
	}
}