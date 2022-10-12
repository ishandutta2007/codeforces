/**
*    author:  Mohamed Abo Okail
*    created: 16/01/2O22
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
		string s; cin >> s;
		int indx = -1;
		for (int i = sz(s) - 2; i >= 0; i--) {
			if((s[i] - '0') + (s[i + 1] - '0') > 9) {
				indx = i;
				break;
			}
		}
		if(indx == -1) {
			int cur = (s[0] - '0') + (s[1] - '0');
			s.erase(s.begin(), s.begin() + 1);
			s[0] = char(cur + '0');
		}
		else {
			int cur = (s[indx] - '0') + (s[indx + 1] - '0');
			s[indx] = char(cur / 10 + '0');
			s[indx + 1] = char(cur % 10 + '0');
		}
		cout << s << endl;
	}
}