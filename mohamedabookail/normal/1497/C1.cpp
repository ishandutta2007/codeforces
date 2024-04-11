/**
*    author:  Mohamed Abo Okail
*    created: 29/O3/2O21
**/
#include <bits/stdc++.h>

using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		if(n % 3 == 0) {
			cout << n / 3 << ' ' << n / 3 << ' ' << n / 3 << endl;
		}
		else if(n % 2 == 1) {
			cout << 1 << ' ' << n / 2 << ' ' << n / 2 << endl; 
		}
		else {
			if((n / 2) % 2 == 0) {
				cout << n / 4 << ' ' << n / 4 << ' ' << n / 2 << endl;
			}
			else {
				cout << 2 << ' ' << n / 2 - 1 << ' ' << n / 2 - 1 << endl;
			}
		}
	}
}