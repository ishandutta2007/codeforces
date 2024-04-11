/**
 *    author:  Mohamed Abo_Okail
 *    created: O7/O2/2O2O
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
	ll n; cin >> n;
	ll ans = 0;
	while(n) {
		if(n % 2) ans++;
		n /= 2;
	}
	cout << ans << o_o;
}