/**
*    author:  Mohamed Abo Okail
*    created: 1O/O4/2O21
**/
#include <bits/stdc++.h>

using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		vector < vector < char > > g(n, vector < char > (n));
		int a = -1, b = -1, c = -1, d = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> g[i][j];
				if(g[i][j] == '*') {
					if(a == -1) {
						a = i;
						b = j;
					}
					else {
						c = i;
						d = j;
					}
				}
			}
		}
		if(a == c) {
			if(a == 0) {
				a++;
				c++;
			}
			else {
				a--;
				c--;
			}
		}
		else if(b == d) {
			if(b == 0) {
				b++;
				d++;
			}
			else {
				b--;
				d--;
			}
		}
		else {
			swap(b, d);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(i == a && j == b || i == c && j == d) {
					cout << '*';
				}
				else {
					cout << g[i][j];
				}
			}
			cout << endl;
		}
	}
}