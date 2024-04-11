/**
*    author:  Mohamed AboOkail
*    created: 15/12/2O2O
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
		string a = s;
		reverse(a.begin(), a.end());
		if(s[0] == '2' && s[1] == '0' && s[2] == '2' && s[3] == '0') {
			cout << "YES" << endl;
		}
		else if(a[0] == '0' && a[1] == '2' && a[2] == '0' && a[3] == '2') {
			cout << "YES" << endl;
		}
		else {
			if(s[0] == '2' && s[n - 3] == '0' && s[n - 2] == '2' && s[n - 1] == '0') {
				cout << "YES" << endl;
			}
			else if(s[0] == '2' && s[1] == '0' && s[n - 2] == '2' && s[n - 1] == '0') {
				cout << "YES" << endl;
			}
			else if(s[0] == '2' && s[1] == '0' && s[2] == '2' && s[n - 1] == '0') {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
}