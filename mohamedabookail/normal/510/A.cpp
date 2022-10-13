/**
 *    author:  Mohamed Abo_Okail
 *    created: 25/O1/2O2O
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
	int n, m; cin >> n >> m;
	int f = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if(i % 2) {
				cout << '#';
			}
			else {
				if(f % 2 && j == m) {
					cout << '#';
				}
				else if(!(f % 2) && j == 1) {
					cout << '#';
				}
				else {
					cout << '.';
				}
			}
		}
		cout << o_o;
		if(i % 2) { f++; }
	}
}