/**
*    author:  Mohamed Abo Okail
*    created: O5/11/2O21
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
	
	vector < vector < char > > g(3, vector < char > (3));
	int x = 0, o = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> g[i][j];
			x += (g[i][j] == 'X');
			o += (g[i][j] == '0');
		}
	}
	bool ok1 = 0, ok2 = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if(i == 0) {
				if(g[i][j] == g[i + 1][j] && g[i][j] == g[i + 2][j]) {
					ok1 |= (g[i][j] == 'X');
					ok2 |= (g[i][j] == '0');
				}
			}
			if(j == 0) {
				if(g[i][j] == g[i][j + 1] && g[i][j] == g[i][j + 2]) {
					ok1 |= (g[i][j] == 'X');
					ok2 |= (g[i][j] == '0'); 
				}
			}
		}
	}
	if(g[0][0] == g[1][1] && g[0][0] == g[2][2]) {
		ok1 |= (g[0][0] == 'X');
		ok2 |= (g[0][0] == '0');
	}
	if(g[0][2] == g[1][1] && g[0][2] == g[2][0]) {
		ok1 |= (g[0][2] == 'X');
		ok2 |= (g[0][2] == '0');
	}
	if((ok1 && ok2) || (abs(x - o) > 1) || o > x || (ok1 && x == o) || (ok2 && x > o)) {
		cout << "illegal" << endl;
	}
	else if(ok1) {
		cout << "the first player won" << endl;
	}
	else if(ok2) {
		cout << "the second player won" << endl;
	}
	else if(x + o == 9) {
		cout << "draw" << endl;
	}
	else if(o < x) {
		cout << "second" << endl;
	}
	else {
		cout << "first" << endl;
	}
}