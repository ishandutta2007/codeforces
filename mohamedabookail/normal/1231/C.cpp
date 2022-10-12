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
	int n, m; cin >> n >> m;
	bool bol = 1;
	int sum = 0;
	vector < vector < int > > v((n), vector < int > (m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	for (int i = n - 2; i >= 0; i--) {
		for (int j = m - 2; j >= 0; j--) {
			if(!v[i][j]) v[i][j] = min(v[i][j + 1], v[i + 1][j]) - 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum += v[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if(v[i][j] <= v[i][j - 1]) bol = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if(v[j][i] <= v[j - 1][i]) bol = 0;
		}
	}
	cout << (bol ? sum : -1) << o_o;
}