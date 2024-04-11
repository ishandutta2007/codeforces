/**
*    author:  Mohamed Abo Okail
*    created: 1O/1O/2O21
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
		ll ar[5] = {0};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> a[i][j];
				ar[j] += (a[i][j] == 1);
			}
		}
		bool ok = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = i + 1; j < 5; j++) {
				if(ar[i] >= n / 2 && ar[j] >= n / 2) {
					set < int > st;
					for (int k = 0; k < n; k++) {
						if(a[k][i] == 1) {
							st.insert(k + 1);
						}
						if(a[k][j] == 1) {
							st.insert(k + 1);
						}
					}
					if(sz(st) == n) ok = 1;
				}
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}