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
	ll n, m, z; cin >> n >> m >> z;
	ll nemo = 0, x = n;
	map < int, bool > mp;
	while(n <= z) {
		mp[n] = true;
		n += x;
	}
	for (int i = 1; i <= z; i++) {
		if(!(i % m) && mp[i]) {
			nemo++;
		}
	}
	cout << nemo << o_o;
}