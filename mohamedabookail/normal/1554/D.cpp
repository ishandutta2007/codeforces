/**
*    author:  Mohamed Abo Okail
*    created: 29/O7/2O21
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
		ll n; cin >> n;
		if(n <= 26) {
			char ch = 'a';
			for (int i = 0; i < n; i++) {
				cout << ch;
				ch++;
				if(ch > 'z') ch = 'a';
			}
			cout << endl;
		}
		else {
			string s = "";
			int x = n / 2;
			for (int i = 0; i < x; i++) {
				s.push_back('a');
			}
			s.push_back('b');
			for (int i = 1; i < x; i++) {
				s.push_back('a');
			}
			if(n & 1) {
				s.push_back('c');
			}
			cout << s << endl;
		}
	}
}