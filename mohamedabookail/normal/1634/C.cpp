/**
*    author:  Mohamed Abo Okail
*    created: O9/O2/2O22
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
		ll cur = n * k;
		ll a = cur / 2, b = (cur + 1) / 2;
		if(a % k || b % k) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		ll flagA = 1, flagB = 2;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				if(i & 1) {
					cout << flagB << ' ';
					flagB += 2;
				}
				else {
					cout << flagA << ' ';
					flagA += 2;
				}
			}
			cout << endl;
		}
	}
}