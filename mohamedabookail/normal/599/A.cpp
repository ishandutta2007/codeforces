/**
 *    author:  Mohamed Abo_Okail
 *    created: 25/O1/2O2O
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
	ll a, b, c; cin >> a >> b >> c;
	ll nemo = (a + b) * 2;
	ll nemoo = (a + b + c);
	ll nemooo = (a * 2) + (c * 2);
	ll nemoooo = (b * 2) + (c * 2);
	cout << min({nemo, nemoo, nemooo, nemoooo}) << o_o;
}