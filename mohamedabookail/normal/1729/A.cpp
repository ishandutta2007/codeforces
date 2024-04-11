/**
*    author:  Mohamed Abo Okail
*    created: 12/O9/2O22
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
		 int a, b, c;
		 cin >> a >> b >> c;
		 ll x = a - 1;
		 ll y = abs(b - c);
		 if(c != 1) {
			y += c - 1;
		 }
		 if(x < y) {
			cout << 1 << endl;
		 }
		 else if(y < x) {
			cout << 2 << endl;
		 }
		 else {
			cout << 3 << endl;
		 }
	}
}