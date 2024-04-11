/**
 *    author:  Mohamed Abo_Okail
 *    created: 18/O1/2O2O
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	ll n; cin >> n;
	if((n - 2) % 3) {
		cout << 1 << ' ' << 1 << ' ' << n - 2 << endl;
	}
	else {
		cout << 1 << ' ' << 2 << ' ' << n - 3 << endl;
	}
}