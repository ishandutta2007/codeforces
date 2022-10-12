/**
*    author:  Mohamed Abo Okail
*    created: 25/O4/2O22
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
		int n;
		cin >> n;
		vector < string > a(n - 2);
		for (int i = 0; i < n - 2; i++) {
			cin >> a[i];
		}
		string ans = a[0];
		for (int i = 1; i < n - 2; i++) {
			if(ans.back() != a[i][0]) {
				ans += a[i];
			}
			else {
				ans += a[i][1];
			}
		}
		string x(n - sz(ans), 'b');
		ans = x + ans;
		cout << ans << endl;
	}
}