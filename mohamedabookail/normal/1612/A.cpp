/**
*    author:  Mohamed Abo Okail
*    created: 22/11/2O21
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
		int x, y; cin >> x >> y;
		if(x % 2 == 0 && y % 2 == 1) {
			cout << "-1 -1" << endl;
		}
		else if(x % 2 == 1 && y % 2 == 0) {
			cout << "-1 -1" << endl;
		}
		else {
			if(x > y) {
				cout << (x - y) / 2 << ' ' << y << endl;
			}
			else {
				cout << x << ' ' << (y - x) / 2 << endl;
			}
		}
	}
}