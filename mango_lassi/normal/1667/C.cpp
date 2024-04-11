#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

// Choose k rows and columns that you DO NOT place queens on
// Possible to place queens to cover all of the intersections, IFF number of diags <= n - k
// number of diags = # of different values of r_i - c_j for skipped rows i, j
// The number of different values is at least 2k - 1
// -> n - k >= 2k - 1
// -> k <= (n + 1) / 3

// n = 2
// Q *
// * 0

// n = 5
// Q * * * *
// * * Q * *
// * Q * * *
// * * * 0 0
// * * * 0 0

// n = 8
// Q * * * * * * * 
// * * Q * * * * * 
// * * * * Q * * * 
// * Q * * * * * * 
// * * * Q * * * * 
// * * * * * 0 0 0 
// * * * * * 0 0 0 
// * * * * * 0 0 0 

// n = 11
//  Q * * * * * * * * * * 
//  * * Q * * * * * * * * 
//  * * * * Q * * * * * * 
//  * * * * * * Q * * * * 
//  * Q * * * * * * * * * 
//  * * * Q * * * * * * * 
//  * * * * * Q * * * * * 
//  * * * * * * * 0 0 0 0 
//  * * * * * * * 0 0 0 0 
//  * * * * * * * 0 0 0 0 
//  * * * * * * * 0 0 0 0 

vector<pair<int, int>> solve(int n) {
	if (n == 1) {
		return {{1, 1}};
	} else if (n % 3 != 2) {
		auto tmp = solve(n - 1);
		for (auto& pr : tmp) {
			++pr.first;
			++pr.second;
		}
		tmp.emplace_back(1, 1);
		return tmp;
	} else {
		int k = (n + 1) / 3;
		vector<pair<int, int>> res = {{1, 1}};
		for (int i = 1; i < n - k; ++i) {
			int y = res.back().first + 1;
			int x = ((res.back().second + 1) % (n - k)) + 1;
			res.emplace_back(y, x);
		}
		return res;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	auto res = solve(n);
	cout << res.size() << '\n';
	for (auto pr : res) cout << pr.first << ' ' << pr.second << '\n';
}