/**
*    author:  Mohamed Abo Okail
*    created: 18/O9/2O22
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
		vector < string > a(n), b(n), c(n);
		map < string , int > mp;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			mp[b[i]]++;
		}
		for (int i = 0; i < n; i++) {
			cin >> c[i];
			mp[c[i]]++;
		}
		int A = 0, B = 0, C = 0;
		for (int i = 0; i < n; i++) {
			if(mp[a[i]] == 1) A += 3;
			if(mp[b[i]] == 1) B += 3;
			if(mp[c[i]] == 1) C += 3;

			if(mp[a[i]] == 2) A += 1;
			if(mp[b[i]] == 2) B += 1;
			if(mp[c[i]] == 2) C += 1;
		}
		cout << A << ' ' << B << ' ' << C << endl;
	}
}