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
	int n; string s; cin >> n >> s;
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		if(s[i] == 'U' && s[i - 1] == 'R') cnt++, i++;
		else if(s[i] == 'R' && s[i - 1] == 'U') cnt++, i++;
	}
	cout << n - cnt << line;
}