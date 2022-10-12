/**
 *    author:  Mohamed Abo_Okail
 *    created: 20/O1/2O2O
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"
 
int main() 
{
	std::ios_base::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	vector <vector<char>> grid(n, vector<char>(m));
	vector <pair<int, int>> ans(2);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(grid[i][j] == 'B') {
				if(ans[0].first == 0 && ans[0].second == 0) {
					ans[0].first  = (i + 1);
					ans[0].second = (j + 1);
					ans[1].first  = (i + 1);
					ans[1].second = (j + 1);
				}
				else {
					ans[1].first  = (i + 1);
					ans[1].second = (j + 1);
				}
			}
		}
	}
	int a = (ans[0].first + ans[1].first) / 2,
		b = (ans[0].second + ans[1].second) / 2;
	cout << a << ' ' << b << endl;
}