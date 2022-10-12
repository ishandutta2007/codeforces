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

ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}

ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	vector < vector < int > > v((m), vector < int > (5, 0));
	int nemo = 0;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			v[j][s[j] - 65]++;
		}
	}
	for (int i = 0; i < m; i++) {
		int oo; cin >> oo;
		nemo += oo * max({v[i][0], v[i][1], v[i][2], v[i][3], v[i][4]});
	}
	cout << nemo << o_o;
}