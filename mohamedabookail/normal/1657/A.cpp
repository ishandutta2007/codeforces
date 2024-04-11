/**
*    author:  Mohamed Abo Okail
*    created: 22/O3/2O22
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

	int t;
	cin >> t;
	while(t--) {
		ll a, b;
		cin >> a >> b;
		if(a + b == 0) {
			cout << 0 << endl;
			continue;
		}
		ll cur = a * a + b * b;
		if(int(sqrt(cur)) * int(sqrt(cur)) == cur) {
			cout << 1 << endl;
		}
		else {
			cout << 2 << endl;
		}
	}
}