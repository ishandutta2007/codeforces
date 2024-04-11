/**
*    author:  Mohamed Abo Okail
*    created: 1O/O5/2O22
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
		string s; cin >> s;
		int sum1 = (s[0] - '0') + (s[1] - '0') + (s[2] - '0');
		int sum2 = (s[3] - '0') + (s[4] - '0') + (s[5] - '0');
		cout << (sum1 == sum2 ? "YES" : "NO") << endl;
	}
}