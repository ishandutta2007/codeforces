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
	
	string s;
	cin >> s;
	int a = 0, b = 0;
	bool ok = 0;
	for (int i = 0; i < s.size(); i++) {
		if(s[i] == '1') {
			a++;
			b = 0;
		}
		else {
			b++;
			a = 0;
		}
		if(a == 7 || b == 7) {
			ok = 1;
			break;
		}
	}
	cout << (ok ? "YES" : "NO") << endl;
}