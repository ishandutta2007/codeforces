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
	ll a, b; cin >> a >> b;
	ll nemo = min(a, b);
	for (int i = nemo - 1; i > 1; i--) {
		nemo *= i;
	}
	cout << nemo << o_o;
}