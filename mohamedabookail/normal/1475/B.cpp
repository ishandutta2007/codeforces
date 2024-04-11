/**
*    author:  Mohamed AboOkail
*    created: 25/01/2O21
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
		long long ans = n / 2020;
		long long cur = n % 2020;
		cout << (cur <= ans ? "YES" : "NO") << "\n";
	}
}