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
	int cnt = 0;
	while(true) {
		bool ok = 0;
		for (int i = 1; i < sz(s); i++) {
			if(s[i] == s[i - 1]) {
				s.erase(i - 1, 2);
				cnt++;
				i -= (i == 1 ? 1 : 2);
				ok = 1;
			}
		}
		if(!ok) break;
	}
	cout << (cnt & 1 ? "Yes" : "No") << endl;
}