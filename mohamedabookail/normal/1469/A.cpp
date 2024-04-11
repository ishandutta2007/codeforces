/**
*    author:  Mohamed AboOkail
*    created: 11/01/2O21
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
		string s;
		cin >> s;
		if(s.size() & 1)
			cout << "NO" << "\n";
		else if(s.front() == ')')
			cout << "NO" << "\n";
		else if(s.back() == '(')
			cout << "NO" << "\n";
		else
			cout << "YES" << "\n";
	}
}