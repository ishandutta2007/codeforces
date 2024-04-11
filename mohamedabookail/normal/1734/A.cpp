/**
*    author:  Mohamed Abo Okail
*    created: 23/O9/2O22
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
		 vector < int > a(n);
		 for (int i = 0; i < n; i++) {
			 cin >> a[i];
		 }
		 sort(all(a));
		 int mn = 1e9;
		 for (int i = 0; i < n - 2; i++) {
			 mn = min(mn, a[i + 1] - a[i] + a[i + 2] - a[i + 1]);
		 }
		 cout << mn << endl;
	}
}