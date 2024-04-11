/**
 *    author:  Mohamed Abo_Okail
 *    created: 16/O1/2O2O
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		ll n, a, b, c; cin >> n >> a >> b >> c;
		cout << (n / c) + ((n / c) / a) * b << endl;
	}
}