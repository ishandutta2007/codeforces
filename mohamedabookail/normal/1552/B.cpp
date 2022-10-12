/**
*    author:  Mohamed Abo Okail
*    created: 29/O7/2O21
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
		vector < vector < int > > a(n, vector < int > (5));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> a[i][j];
			}
		}
		int indx = 1;
		for (int i = 1; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < 5; j++) {
				cnt += a[i][j] < a[indx - 1][j];
			}
			if(cnt >= 3) {
				indx = i + 1;
			}
		}
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < 5; j++) {
				cnt += a[i][j] < a[indx - 1][j];
			}
			if(cnt >= 3) {
				indx = -1;
				break;
			}
		}
		cout << indx << endl; 
	}
}