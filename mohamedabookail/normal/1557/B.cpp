/**
*    author:  Mohamed Abo Okail
*    created: 09/O8/2O21
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
		int n, k; cin >> n >> k;
		vector < ll > a(n), b(n);
		map < ll , ll > mp;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		if(n == 1) {
			cout << "YES" << endl;
			continue;
		}
		b = a;
		sort(all(b));
		for (int i = 0; i < n; i++){
			mp[b[i]] = i;
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if(i < n - 1) {
				if(mp[a[i]] != mp[a[i + 1]] - 1) {
					cnt++;
				}
			}
			else {
				cnt++;
			}
		}
		cout << (cnt <= k ? "YES" : "NO") << endl;
	}
}