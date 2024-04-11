/**
*    author:  Mohamed Abo Okail
*    created: 10/O9/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";
 
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		string s; cin >> s;
		vector < vector < char > > grid(n, vector < char > (n, '0'));
		for (int i = 0; i < n; i++) {
			grid[i][i] = 'X';
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(i == j) continue;
				if(s[i] == '1') {
					grid[i][j] = '=';
				}
			}
		}

		for (int i = 0; i < n; i++) {
			bool ok = 0;
			for (int j = 0; j < n; j++) {
				if(i == j) continue;
				if(s[i] == '1') break;
				if(grid[i][j] != '0') continue;
				if(grid[j][i] == '=') {
					grid[i][j] = '=';
				}
				else if(grid[j][i] == '-') {
					grid[i][j] = '+';
				}
				else if(grid[j][i] == '+') {
					grid[i][j] = '-';
				}
				else {
					if(ok == 1) {
						grid[i][j] = '-';
						grid[j][i] = '+';
					}
					else {
						grid[i][j] = '+';
						grid[j][i] = '-';	
					}
					ok = 1;
				}
			}
		}
		bool ok = 1;
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if(grid[i][j] == '+') cnt++;
			}
			if(s[i] == '2' && cnt == 0) ok = 0;
		}
		if(ok) {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << grid[i][j];
				}
				cout << endl;
			}
		} 
		else cout << "NO" << endl;
	}
}