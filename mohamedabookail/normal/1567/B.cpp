/**
*    author:  Mohamed Abo Okail
*    created: 10/O9/2O21
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
	
	vector < ll > x(3e5 + 5);
	x[0] = 0;
	for (int i = 1; i < 3e5 + 5; i++) {
		x[i] = (i ^ x[i - 1]);
	}
	int t; cin >> t;
	while(t--) {
		ll a, b; cin >> a >> b;
		if(x[a - 1] == b) {
			cout << a << endl;
		}
		else if(x[a] == b) {
			cout << a + 2 << endl;
		}
		else {
			cout << a + 1 << endl;
		}
	}
}