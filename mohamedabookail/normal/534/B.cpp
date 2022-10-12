/**
*    author:  Mohamed AboOkail
*    created: 18/02/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int v1, v2;
	cin >> v1 >> v2;
	int t, d;
	cin >> t >> d;
	vector < int > a(t), b(t);
	for (int i = 0; i < t; i++) {
		a[i] = v1 + i * d;
		b[t - i - 1] = v2 + i * d;
	}
	long long tot = 0;
	for (int i = 0; i < t; i++) {
		tot += min(a[i], b[i]);
	}
	cout << tot << "\n";
}