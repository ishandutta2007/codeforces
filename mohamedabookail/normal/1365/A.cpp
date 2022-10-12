/**
 *    author:  Mohamed Abo_Okail
 *    created: O7/O6/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
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
	int t; cin >> t;
	while(t--) {
		int n, m; cin >> n >> m;
		vector < vector < int > > v(n, vector < int > (m));
		map < int, bool > row, col;
		int a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> v[i][j];
				if(v[i][j] == 1) {
					col[i] = 1;
					row[j] = 1;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if(col[i] != 1) a++;
		}
		for (int i = 0; i < m; i++) {
			if(row[i] != 1) b++;
		}
		cout << ((min(a, b) & 1) ? "Ashish" : "Vivek") << endl;
	}
}