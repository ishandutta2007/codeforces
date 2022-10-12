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
		 int n; cin >> n;
		 string s = "000000000";
		 for (int i = 8; i >= 0 ; i--) {
			 if(n >= i + 1) {
				s[i] = char((i + 1) + '0');
				n -= (i + 1);
			 }
			 else {
				s[i] = char(n + '0');
				break;
			 }
		 }
		 for (int i = 0; i < 9; i++) {
			 if(s[i] != '0') {
				cout << s[i];
			 }
		 }
		 cout << endl;
	}
}