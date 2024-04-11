/**
*    author:  Mohamed Abo Okail
*    created: 3O/O4/2O21
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
		ll n, m, k; cin >> n >> m >> k;
		ll a = 0, b = 0;
		a = n - 1 + (m - 1) * n;
		b = m - 1 + (n - 1) * m;

		cout << (a == k || b == k ? "YES" : "NO") << endl;
	}
}