/**
*    author:  Mohamed Abo Okail
*    created: 2O/O5/2O21
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
		ll n, m, k; cin >> n >> m >> k;
		ll i = 0, j = 0;
		j = k / n;
		if(k % n) {
			j++;
			i = k % n; 
		}
		else {
			i = n;
		}
		cout << (i - 1) * m + j << endl;
	}
}