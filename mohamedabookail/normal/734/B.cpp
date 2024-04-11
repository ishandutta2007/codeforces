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
	ll a, b, c, d; cin >> a >> b >> c >> d;
	ll nemo = min({a, c, d}); a -= nemo;
	cout << nemo * 256 + min(a, b) * 32 << o_o;
}