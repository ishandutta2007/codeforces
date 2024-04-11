/**
 *    author:  Mohamed Abo_Okail
 *    created: O2/O1/2O2O
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int n; cin >> n;
	vector <vector <char>> grid(n, vector <char>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	} ll ans = 0;
	if(n <= 2) { return cout << 0, 0; }
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if(grid[i][j] == 'X') {
				if(grid[i - 1][j - 1] == 'X' &&
				   grid[i + 1][j + 1] == 'X' &&
				   grid[i - 1][j + 1] == 'X' &&
				   grid[i + 1][j - 1] == 'X') {
				   ans++;
				}
			}
		}
	} cout << ans << endl;
}