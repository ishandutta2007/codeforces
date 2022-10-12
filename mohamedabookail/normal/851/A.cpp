/**
 *    author:  Mohamed Abo_Okail
 *    created: 23/O1/2O2O
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
	ll n, k, t; cin >> n >> k >> t;
	if(t <= k) {
		cout << t << o_o;
	}
	else if(t > k && t <= n) {
		cout << k << o_o;
	}
	else {
		cout << max(k - (t - n), 0ll) << o_o;
	}
}