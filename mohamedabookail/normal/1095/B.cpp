/**
*    author:  Mohamed AboOkail
*    created: 30/12/2O2O
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector < int > a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	cout << (n == 2 ? 0 : min(a[n - 2] - a[0], a[n - 1] - a[1])) << endl; 
}