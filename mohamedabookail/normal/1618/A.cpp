/**
*    author:  Mohamed Abo Okail
*    created: 25/O4/2O22
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
		vector < ll > a(7);
		for (int i = 0; i < 7; i++) {
			cin >> a[i];
		}
		sort(all(a));
		if(a[0] + a[1] + a[2] == a[6]) {
			cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
		}
		else {
			cout << a[0] << ' ' << a[1] << ' ' << a[3] << endl;
		}
	}
}