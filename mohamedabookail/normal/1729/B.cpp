/**
*    author:  Mohamed Abo Okail
*    created: 12/O9/2O22
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
	
	int t; cin >> t;
	while(t--) {
		 int n;
		 cin >> n;
		 string s; cin >> s;
		 string ans = "";
		 for (int i = 0; i < sz(s); i++) {
			 if(i + 3 < sz(s) && s[i + 3] == '0') {
				ans.push_back(char('a' + (s[i] - '0') - 1));
			 }
			 else if(i + 2 < sz(s) && s[i + 2] == '0') {
				 int x = (s[i] - '0') * 10 + (s[i + 1] - '0');
				 ans.push_back(char('a' + x - 1));
				 i += 2;
			 }
			 else {
				 ans.push_back(char('a' + (s[i] - '0') - 1));
			 }
		 }
		 cout << ans << endl;
	}
}