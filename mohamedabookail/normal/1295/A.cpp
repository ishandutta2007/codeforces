/**
 *    author:  Mohamed Abo_Okail
 *    created: 29/O1/2O2O
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
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		if(!(n % 2)) {
			for (int i = 0; i < n / 2; i++) {
				cout << 1;
			}
			cout << o_o;
		} 
		else {
			cout << 7;
			for (int i = 1; i < n / 2; i++) {
				cout << 1;
			}
			cout << o_o;
		}
	}
}