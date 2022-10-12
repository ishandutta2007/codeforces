/**
*    author:  Mohamed AboOkail
*    created: 10/01/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector < int > a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	b = a;
	sort(b.begin(), b.end());
	int x = -1, y = -1, z = -1;
	for (int i = 0; i < n; i++) {
		if(x == -1 && a[i] != b[i]) x = i;
		if(a[i] != b[i]) y = i;
	}
	if(x == -1 && y == -1) {
		cout << "yes" << "\n";
		cout << "1 1" << "\n";
		return 0;
	}
	z = y;
	for (int i = x; i <= z; i++) {
		swap(a[i], a[z]);
		z--;
	}
	if(is_sorted(a.begin(), a.end())) {
		cout << "yes" << "\n";
		cout << ++x << ' ' << ++y << "\n";
	}
	else {
		cout << "no" << "\n";
	}
}