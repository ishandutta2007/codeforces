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
		string s; cin >> s;
		set < char > st;
		for (int i = 0; i < n; i++) {
			st.insert(s[i]);
		}
		cout << n + sz(st) << endl;
	}
}