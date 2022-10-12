/**
*    author:  Mohamed Abo Okail
*    created: 22/O7/2O21
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
		vector < int > a(6);
		for (int i = 0; i < 6; i++) {
			cin >> a[i];
		}
		if(a[0] < a[2]) swap(a[0], a[2]);
		if(a[1] < a[3]) swap(a[1], a[3]);
		int res = (a[0] - a[2]) + (a[1] - a[3]);
		int cur = 0;
		if(a[4] >= a[2] && a[4] <= a[0] && a[5] >= a[3] && a[5] <= a[1]) {
			cur++;
		}
		if(a[4] == a[0] && a[4] == a[2] || a[5] == a[1] && a[5] == a[3]) {
			cur++;
		}
		if(cur == 2) {
			res += 2;
		}
		cout << res << endl;
	}
}