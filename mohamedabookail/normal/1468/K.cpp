/**
*    author:  Mohamed AboOkail
*    created: 25/12/2O2O
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		string s;
		cin >> s;
		vector < pair < int, int > > pr;
		int x = 0, y = 0;
		bool ok = 0;
		for (int i = 0; i < s.size(); i++) {
			if(s[i] == 'R') x++;
			if(s[i] == 'L') x--;
			if(s[i] == 'U') y++;
			if(s[i] == 'D') y--;
			pr.push_back(make_pair(x, y));
		}
		for (int i = 0; i < pr.size(); i++) {
			x = 0;
			y = 0;
			for (int j = 0; j < s.size(); j++) {
				if(s[j] == 'R') x++;
				if(s[j] == 'L') x--;
				if(s[j] == 'U') y++;
				if(s[j] == 'D') y--;
				if(pr[i].first == x && pr[i].second == y) {
					if(s[j] == 'R') x--;
					if(s[j] == 'L') x++;
					if(s[j] == 'U') y--;
					if(s[j] == 'D') y++;
				}
			}
			if(x == 0 && y == 0) {
				cout << pr[i].first << ' ' << pr[i].second << endl;
				ok = 1;
				break;
			}
		}
		if(!ok) cout << "0 0" << endl;
	}
}