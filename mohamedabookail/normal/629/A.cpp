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
	int n; cin >> n;
	vector < vector < char > > grid(n, vector < char > (n));
	ll nemo = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if(grid[i][j] == 'C') { cnt++; }
		}
		nemo += (cnt * (cnt - 1) / 2);
	}
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if(grid[j][i] == 'C') { cnt++; }
		}
		nemo += (cnt * (cnt - 1) / 2);
	}
	cout << nemo << o_o;
}