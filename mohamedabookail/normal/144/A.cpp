/**
*    author:  Mohamed Abo_Okail
*    created: O1/11/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
int main() {
	std::ios_base::sync_with_stdio(0);
	int n; cin >> n;
	vector < int > a(n);
	int mn = 1e3, mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}
	int idx1 = 0, idx2 = 0;
	for (int i = n - 1; i >= 0 ; i--) {
		if(a[i] == mx) {
			idx1 = i;
		}
	}
	for (int i = 0; i < n; i++) {
		if(a[i] == mn) {
			idx2 = i;
		}
	}
	cout << idx1 + (n - idx2 - 1) - (idx1 > idx2) << endl;
}