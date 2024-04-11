/**
*    author:  Mohamed Abo Okail
*    created: 18/O5/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n"

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector < int > a(n);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt += a[i] == i + 1;
		}
		if(cnt == n) {
			cout << 0 << endl;
		}
		else if(a[0] == 1 || a[n - 1] == n) {
			cout << 1 << endl;
		}
		else if(a[0] == n && a[n - 1] == 1) {
			cout << 3 << endl;
		}
		else {
			cout << 2 << endl;
		}
	}
}