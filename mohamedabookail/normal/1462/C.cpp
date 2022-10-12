/**
*    author:  Mohamed AboOkail
*    created: 15/12/2O2O
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
		long long n;
		cin >> n;
		if(n < 10) {
			cout << n << endl;
			continue;
		}
		if(n > 45) {
			cout << -1 << endl;
			continue;
		}
		string s;
		for (int i = 9; i >= 1; i--) {
			if(n >= i) {
				n -= i;
				s.push_back(i + '0');
			}
		}
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
}