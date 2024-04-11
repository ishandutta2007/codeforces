/**
*    author:  Mohamed Abo Okail
*    created: 17/O4/2O22
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
		int n, a, b;
		cin >> n >> a >> b;
		int e = b;
		string ans = "";
		while(b) {
			ans.push_back('R');
			ans.push_back('B');
			a--;
			b--;
		}
		if(a) {
			ans.push_back('R');
			a--;
		}
		b = e;
		int x = a / (b + 1), y = a % (b + 1);
		for (int i = 0; i < sz(ans); i++) {
			if(ans[i] == 'B') {
				string s(x, 'R');
				if(y) {
					s.push_back('R');
					y--;
				}
				cout << s;
				cout << ans[i];
			}
			else {
				cout << ans[i];
			}
		}
		string s(x, 'R');
		if(y) {
			s.push_back('R');
			y--;
		}
		cout << s << endl;
	}
}