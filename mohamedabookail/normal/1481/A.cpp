/**
*    author:  Mohamed AboOkail
*    created: 11/02/2O21
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
		int x, y;
		cin >> x >> y;
		string s;
		cin >> s;
		map < char, int > mp;
		for(auto ch : s) {
			mp[ch]++;
		}
		if(x >= 0 && y >= 0 && mp['R'] >= x && mp['U'] >= y) {
			cout << "YES" << "\n";
		}
		else if(x <= 0 && y >= 0 && mp['L'] >= -x && mp['U'] >= y) {
			cout << "YES" << "\n";
		}
		else if(x <= 0 && y <= 0 && mp['L'] >= -x && mp['D'] >= -y) {
			cout << "YES" << "\n";
		}
		else if(x >= 0 && y <= 0 && mp['R'] >= x && mp['D'] >= -y) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}
}