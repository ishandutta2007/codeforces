/**
*    author:  Mohamed AboOkail
*    created: 15/02/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector < vector < int > > a(n, vector < int > (m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if((i + j) % 2 == 0) {
				cout << 720720 << ' ';
			}
			else {
				cout << a[i][j] * a[i][j] * a[i][j] * a[i][j] + 720720 << ' ';
			}
		}
		cout << "\n";
	}
}