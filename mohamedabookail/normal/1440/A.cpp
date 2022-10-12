/**
*    author:  Mohamed AboOkail
*    created: 14/02/2O21
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
		int n, a, b, h;
		cin >> n >> a >> b >> h;
		string s;
		cin >> s;
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			if(h >= a && h >= b) continue;
			if(a < b) {
				if(s[i] == '1' && a + h < b) {
					s[i] = '0';
					ans += h;
				}
			}
			else {
				if(s[i] == '0' && b + h < a) {
					s[i] = '1';
					ans += h;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			ans += (s[i] == '1' ? b : a);
		}
		cout << ans << "\n";
	}
}