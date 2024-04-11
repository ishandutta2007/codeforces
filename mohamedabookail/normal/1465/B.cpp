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
		unsigned long long n;
		cin >> n;
		for(unsigned long long i = n; ; i++) {
			unsigned long long cur = i;
			bool ok = 1;
			while(cur) {
				if(cur % 10 && i % (cur % 10)) {
					ok = 0;
					break;
				}
				cur /= 10;
			}
			if(ok) {
				cout << i << endl;
				break;
			}
		}
	}
}