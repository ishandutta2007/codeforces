/**
*    author:  Mohamed Abo Okail
*    created: 17/01/2O22
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
		map < int , int > mp;
		int x, ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> x;
			mp[x]++;
			if(mp[x] == 1) {
				ans++;
			}
			else if(!mp[-x]) {
				mp[-x]++;
				ans++;
			}
		}
		cout << ans << endl;
	}
}