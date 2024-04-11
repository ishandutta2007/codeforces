/**
*    author:  Mohamed Abo_Okail
*    created: 27/1O/2O2O
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
		ll a, b; cin >> a >> b;
		cout << (a >= (b + 2) / 2 ? "YES" : "NO") << endl;
	}
}