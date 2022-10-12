/**
*    author:  Mohamed Abo_Okail
*    created: 28/O9/2O2O
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
	int t; cin >> t;
	while(t--) {
		ll n, x; cin >> n >> x;
		n -= 2;
		cout << max((n + x - 1) / x + 1, 1LL) << endl;
	}
}