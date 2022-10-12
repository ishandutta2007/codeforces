/**
 *    author:  Mohamed Abo_Okail
 *    created: 17/O3/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define o_o "\n"
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
	int ar[4]; cin >> ar[0] >> ar[1] >> ar[2] >> ar[3];
	int sum = (ar[0] + ar[1] + ar[2] + ar[3]);
	if(sum % 2) return cout << "NO", 0;
	sum /= 2;
	for (int i = 0; i < 4; i++) {
		if(ar[i] == sum) return cout << "YES", 0;
		for (int j = i + 1; j < 4; j++) {
			if(ar[i] + ar[j] == sum) return cout << "YES", 0;
		}
	}
	cout << "NO";
}