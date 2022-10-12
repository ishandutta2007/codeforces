/**
*    author:  Mohamed AboOkail
*    created: 30/12/2O2O
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
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cout << s[i];
		cnt++;
		i += cnt;
	}
	cout << endl;
}