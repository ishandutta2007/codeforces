/**
*    author:  Mohamed Abo Okail
*    created: 16/O4/2O21
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
		int n; cin >> n;
		vector < ll > a, b;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			if(x & 1) a.push_back(x);
			else b.push_back(x);
		}
		for (int i = 0; i < sz(a); i++) {
			cout << a[i] << ' ';
		}
		for (int i = 0; i < sz(b); i++) {
			cout << b[i] << ' ';
		}
		cout << endl;
	}
}