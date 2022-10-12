/**
*    author:  Mohamed Abo_Okail
*    created: 15/11/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()

int main() {
	std::ios_base::sync_with_stdio(0);
	//freopen("x.in", "r", stdin);
	int t; cin >> t;
	while(t--) {
		ll n, m; cin >> n >> m;
		vector < vector < ll > > a(n, vector < ll > (m));
		ll sum = 0, mn = 1e3, cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				if(a[i][j] > 0) {
					sum += a[i][j];
					mn = min(mn, a[i][j]);
				}
				else {
					sum += abs(a[i][j]);
					mn = min(mn, -a[i][j]);
					cnt++;
				}
			}
		}
		cout << (cnt & 1 ? sum - mn * 2 : sum) << endl;
	}
}