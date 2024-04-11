/**
*    author:  Mohamed Abo Okail
*    created: 12/O9/2O22
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
		 vector < int > ar(n);
		 for (int i = 0; i < n; i++) {
			 cin >> ar[i];
		 }
		 map < int , bool > mp;
		 int ans = 0;
		 for (int i = n - 1; i >= 0 ; i--) {
			 if(mp[ar[i]]) {
				ans = n - sz(mp);
				break;
			 }
			 mp[ar[i]] = 1;
		 }
		 cout << ans << endl;
	}
}