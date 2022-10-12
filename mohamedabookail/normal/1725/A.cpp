/**
*    author:  Mohamed Abo Okail
*    created: 24/O9/2O22
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
	
	ll n, m;
	cin >> n >> m;
	if(m == 1) {
		cout << n - 1 << endl;
	}
	else {
		cout << n * (m - 1) << endl;
	}
}