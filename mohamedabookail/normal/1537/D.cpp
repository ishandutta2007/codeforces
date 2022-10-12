/**
*    author:  Mohamed Abo Okail
*    created: 19/01/2O22
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
		ll n; cin >> n;
		int cnt = 0;
		if(n & 1) {
			cout << "Bob" << endl;
			continue;
		}
		while(n % 2 == 0) {
			n /= 2;
			cnt++;
		}
		cout << (cnt % 2 == 0 || n > 1 ? "Alice" : "Bob") << endl;
	}
}