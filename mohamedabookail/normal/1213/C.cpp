/**
 *    author:  Mohamed Abo_Okail
 *    created: 11/O2/2O2O
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
	ll t; cin >> t;
	while(t--) {
		ll n, m; cin >> n >> m;
		ll nemo = 0;
		bool bol = 1;
		for (int i = 1; i <= 10; i++) {
			if(m * i > n) {
				bol = 0;
				break;
			}
			nemo += m * i % 10;
		}
		if(bol) {
			nemo *= n / (m * 10);
			n = n % (m * 10);
			for (int i = 1; i <= 10; i++) {
				if(m * i > n) break;
				nemo += m * i % 10;
			}
		}
		cout << nemo << o_o;
	}
}