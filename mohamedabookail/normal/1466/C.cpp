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
		int cnt = 0;
		for (int i = 1; i < s.size(); i++) {
			if(s[i] == s[i - 1]) {
				cnt++;
				s[i] = '0';
			}
			else if(i > 1 && s[i] == s[i - 2]) {
				cnt++;
				s[i] = '0';
			}
		}
		cout << cnt << endl;
	}
}