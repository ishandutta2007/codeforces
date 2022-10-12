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
		ll n;
		cin >> n;
		string s; cin >> s;
		vector < ll > ar(n);
		ll tot = 0, mx = 0;
		if(n & 1) {
			mx = (((n + 1) / 2) * (n / 2) + (n / 2 - 1) * (n / 2) / 2) * 2 + n / 2;
		}
		else {
			mx = ((n / 2) * (n / 2) + (n / 2 - 1) * (n / 2) / 2) * 2;
		}
		for (int i = 0; i < n; i++) {
			if(s[i] == 'R') {
				ar[i] = n - i - 1;
			}
			else {
				ar[i] = i;
			}
			tot += ar[i];
		}
		int l = 0, r = n - 1;
		for (int i = 0; i < n; i++) {
			if(tot == mx) {
				cout << mx << ' ';
			}
			else {
				while(s[l] == 'R') {
					l++;
				}
				while(s[r] == 'L') {
					r--;
				}
				if(s[l] == 'L' && l < n / 2 && l < n - r) {
					tot += (n - l - 1) - ar[l];
					l++;
				}
				else {
					tot += r - ar[r];
					r--;
				}
				cout << tot << ' ';
			}
		}
		cout << endl;
	}
}