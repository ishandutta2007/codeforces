/**
*    author:  Mohamed AboOkail
*    created: 28/01/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long n, x;
	cin >> n >> x;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if(x % i == 0 && x / i <= n) {
			ans++;
		}
	}
	cout << ans << "\n";
}