/**
*    author:  Mohamed Abo Okail
*    created: 18/O8/2O21
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
	
	vector < ll > a;
	for (int i = 1; i < 5000; i++) {
		if(i % 10 != 3 && i % 3) {
			a.push_back(i);
		}
	}
	int t; cin >> t;
	while(t--) {
		int k; cin >> k;
		cout << a[k - 1] << endl;
	}
}