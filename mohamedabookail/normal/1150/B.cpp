/**
 *    author:  Mohamed Abo_Okail
 *    created: 13/O2/2O2O
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
	int n; cin >> n;
	vector < vector < char > > grid(n, vector < char > (n));
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
			if(grid[i][j] == '.') cnt++;
		}
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if(grid[i][j] != '.') continue;
			if(grid[i][j - 1] != '.') continue;
			if(grid[i][j + 1] != '.') continue;
			if(grid[i - 1][j] != '.') continue;
			if(grid[i + 1][j] != '.') continue;
			cnt -= 5;
			grid[i][j] = 'x';
			grid[i][j - 1] = 'x';
			grid[i][j + 1] = 'x';
			grid[i - 1][j] = 'x';
			grid[i + 1][j] = 'x';
		}
	}
	cout << (!cnt ? "YES" : "NO") << o_o;
}