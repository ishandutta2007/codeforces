/**
*    author:  Mohamed AboOkail
*    created: 10/01/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		s.push_back('a');
		s.push_back('a');
		s.push_back('b');
		s.push_back('b');
	}
	cout << s.substr(0, n) << "\n";
}