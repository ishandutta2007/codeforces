/**
*    author:  Mohamed Abo Okail
*    created: O6/O6/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n"

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		string s; cin >> s;
		bool ok = 0;
		for (int i = 0; i < 26; i++) {
			if(s.find(char(i + 'a')) == -1) {
				cout << char(i + 'a') << endl;
				ok = 1;
				break;
			}
		}
		if(ok) continue;
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				string ss = "";
				ss.push_back(char(i + 'a'));
				ss.push_back(char(j + 'a'));
				if(s.find(ss) == -1) {
					cout << ss << endl;
					ok = 1;
					break;
				}
			}
			if(ok) break;
		}
		if(ok) continue;

		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				for (int k = 0; k < 26; k++) {
					string ss = "";
					ss.push_back(char(i + 'a'));
					ss.push_back(char(j + 'a'));
					ss.push_back(char(k + 'a'));
					if(s.find(ss) == -1) {
						cout << ss << endl;
						ok = 1;
						break;
					}
				}
				if(ok) break;
			}
			if(ok) break;
		}
	}
}