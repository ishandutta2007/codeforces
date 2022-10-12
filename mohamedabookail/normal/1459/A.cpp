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
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		int x = 0, y = 0;
		for (int i = 0; i < n; i++) {
			if(a[i] > b[i]) {
				x++;
			}
			if(b[i] > a[i]) {
				y++;
			}
		}
		cout << (x == y ? "EQUAL" : (x > y ? "RED" : "BLUE")) << "\n"; 
	}
}