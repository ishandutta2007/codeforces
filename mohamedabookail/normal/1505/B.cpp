/**
*    author:  Mohamed Abo Okail
*    created: 1O/O4/2O21
**/
#include <bits/stdc++.h>

using namespace std;
 
//#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n; cin >> n;
	cout << (n - 1) % 9 + 1 << endl;
}