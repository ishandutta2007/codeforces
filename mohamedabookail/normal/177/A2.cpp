/**
 *    author:  Mohamed.Abo_Okail
 *    created: 23/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int n; cin >> n;
	ll ans = 0;
	vector <vector <int>> v(n, vector <int> (n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(i == j) { ans += v[i][j]; }
			else if((i + j) == (n - 1)) { ans += v[i][j]; }
			else if(i == (n / 2)) { ans += v[i][j]; }
			else if(j == (n / 2)) { ans += v[i][j]; }
		}
	}
	cout << ans << endl;
}