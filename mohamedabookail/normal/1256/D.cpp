/**
*    author:  Mohamed AboOkail
*    created: 01/01/2O21
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
		long long n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		long long one = 0, zero = 0;
		string s2;
		for (long long i = 0; i < n; i++) {
			if(s[i] == '1') one++;
			if(s[i] == '0') {
				if(k >= one) {
					k -= one;
					zero++;
				}
				else {
					s2 = s.substr(i, n);
					break;
				}
			}
		}
		string s3(one, '1'), s4(zero, '0');
		if(one + zero == n) {
			cout << (s4 + s3) << endl;
		}
		else {
			s2.erase(s2.begin(), s2.begin() + 1);
			string s31(one - k, '1'), s32(k, '1');
			s = s4 + (s31 + '0' + s32) + s2;
			cout << s << endl;
		}
	}
}