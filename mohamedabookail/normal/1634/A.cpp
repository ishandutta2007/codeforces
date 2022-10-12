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
		string s; cin >> s;
		string x = s;
		reverse(all(x));
		cout << (k && s != x ? 2 : 1) << endl;
	}
}