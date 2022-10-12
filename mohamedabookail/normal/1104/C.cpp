/**
*    author:  Mohamed Abo Okail
*    created: O2/11/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";
 
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s; cin >> s;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < sz(s); i++) {
		if(s[i] == '0') {
			cnt1++;
			if(cnt1 == 1) {
				cout << "1 1" << endl;
			}
			if(cnt1 == 2) {
				cout << "3 1" << endl;
				cnt1 = 0;
			}
		}
		else {
			cnt2++;
			if(cnt2 == 1) {
				cout << "1 2" << endl;
			}
			if(cnt2 == 2) {
				cout << "2 2" << endl;
			}
			if(cnt2 == 3) {
				cout << "3 2" << endl;
			}
			if(cnt2 == 4) {
				cout << "4 2" << endl;
				cnt2 = 0;
			}
		}
	}
}