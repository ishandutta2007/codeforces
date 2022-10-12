/**
*    author:  Mohamed Abo Okail
*    created: 1O/O4/2O22
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
		string a, b, s;
		cin >> a >> s;
		if(a == s) {
			cout << -1 << endl;
			continue;
		}
		bool ok = 1;
		int indx = sz(s) - 1;
		for (int i = sz(a) - 1; i >= 0 ; i--) {
			if(a[i] <= s[indx]) {
				b.push_back(((s[indx] - '0') - (a[i] - '0')) + '0');
				indx--;
			}
			else {
				if(indx == 0) {
					ok = 0;
					break;
				}
				int cur = (s[indx] - '0') + (s[indx - 1] - '0') * 10;
				cur -= (a[i] - '0');
				if(cur > 9 || cur < 0) {
					ok = 0;
					break;
				}
				b.push_back(cur + '0');
				indx -= 2;
			}
			if(indx < 0 && i) {
				ok = 0;
				break;
			}
		}
		if(!ok) {
			cout << -1 << endl;
			continue;
		}
		while(indx != -1) {
			b.push_back(s[indx--]);
		}
		while(b.back() == '0') {
			b.pop_back();
		}
		reverse(all(b));
		cout << b << endl;
	}
}