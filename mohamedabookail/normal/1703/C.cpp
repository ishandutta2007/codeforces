/**
*    author:  Mohamed Abo Okail
*    created: 21/O9/2O22
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
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			string s; cin >> s;
			for (int j = 0; j < x; j++) {
				if(s[j] == 'U') {
					a[i]--;
				}
				else {
					a[i]++;
				}
				if(a[i] == 10)
					a[i] = 0;
				if(a[i] == -1)
					a[i] = 9;
			}
		}
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}
}