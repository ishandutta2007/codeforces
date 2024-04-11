/**
*    author:  Mohamed Abo_Okail
*    created: 13/11/2O2O
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
	//freopen("x.in", "r", stdin);
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		set < ll > st;
		for (int i = 0; i < n; i++) {
			ll oo; cin >> oo;
			st.insert(oo);
		}
		cout << (sz(st) != n ? "YES" : "NO") << endl;
	}
}