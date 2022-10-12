/**
*    author:  Mohamed Abo Okail
*    created: 07/O7/2O21
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
		int cnt = 0;
		for (int i = 0; i < n * 2; i++) {
			int x; cin >> x;
			cnt += (x & 1);
		}
		cout << (cnt == n ? "Yes" : "no") << endl;
	}
}