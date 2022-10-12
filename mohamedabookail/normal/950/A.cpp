/**
 *    author:  Mohamed Abo_Okail
 *    created: 19/O4/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define line "\n"
#define ll long long
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	int a, b, c; cin >> a >> b >> c;
	if(a < b) swap(a, b);
	if(a >= b + c) cout << (b + c) * 2;
	else cout << (c - (a - b)) / 2 * 2 + a * 2;
	cout << line;
}