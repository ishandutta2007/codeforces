/**
*    author:  Mohamed Abo Okail
*    created: 31/O3/2O22
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

	ll a, b;
	cin >> a >> b;
	ll ans = 0;
	while(b) {
		ans *= 10;
		ans += (b % 10);
		b /= 10;
	}
	cout << ans + a << endl;
}