/**
*    author:  Mohamed Abo Okail
*    created: 2O/O9/2O22
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
		int n, m, x, y, d;
		cin >> n >> m >> x >> y >> d;
		if(x - 1 > d && m - y > d) {
			cout << (n + m - 2) << endl;
		}
		else if(n - x > d && y - 1 > d) {
			cout << (n + m - 2) << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
}