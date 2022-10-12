/**
*    author:  Mohamed Abo Okail
*    created: 22/O9/2O22
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
		int a, b;
		cin >> a >> b;
		string ans = "";
		if(a > b) {
			for (int i = 0; i < b; i++) {
				ans += '0';
				ans += '1';
			}
			string x(a - b, '0');
			ans += x;
		}
		else {
			for (int i = 0; i < a; i++) {
				ans += '1';
				ans += '0';
			}
			string x(b - a, '1');
			ans += x;
		}
		cout << ans << endl;
	}
}