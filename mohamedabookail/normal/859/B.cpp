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
	ll n; cin >> n;
	ll a = sqrt(n), b = n / a;
	cout << (a + b) * 2 + (n % (a * b) ? 2 : 0) << o_o;
}