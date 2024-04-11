/**
 *    author:  Mohamed Abo_Okail
 *    created: 24/O1/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define o_o "\n"
#define ll long long

int main()
{
	std::ios_base::sync_with_stdio(0);
	ll n, t; cin >> n >> t;
	vector < ll > v(n);
	ll nemo = 1;
	if(n == 1) { return cout << 1, 0; }
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = n - 1; i > 0; i--) {
		if(v[i] - v[i - 1] > t) { break; };
		nemo++;
	}
	cout << nemo << o_o;
}