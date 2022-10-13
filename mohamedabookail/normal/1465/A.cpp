/**
*    author:  Mohamed AboOkail
*    created: 01/01/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		while(!s.empty() && s.back() == ')') {
			s.pop_back();
		}
		cout << (n - s.size() > s.size() ? "YES" : "NO") << endl;
	}
}