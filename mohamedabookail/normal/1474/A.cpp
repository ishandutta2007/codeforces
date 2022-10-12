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
		int n;
		cin >> n;
		string s;
		cin >> s;
		string ans(n, '1');
		for (int i = 1; i < n; i++) {
			if((s[i - 1] - '0') + (ans[i - 1] - '0') == 2) {
				ans[i] = (s[i] == '0' ? '1' : '0');
			}
			else if((s[i - 1] - '0') + (ans[i - 1] - '0') == 1) {
				ans[i] = s[i];
			}
		}
		cout << ans << "\n";
	}
}