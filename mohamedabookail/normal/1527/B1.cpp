/**
*    author:  Mohamed Abo Okail
*    created: 2O/O5/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n"
 
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		string s; cin >> s;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += s[i] == '1';
		}
		if(n & 1) {
				cout << (s[n / 2] == '1' || n == 1 || n - cnt == 1 ? "BOB" : "ALICE") << endl;
		}
		else {
			cout << "BOB" << endl;
		}
	}
}