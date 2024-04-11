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
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(i == j) {
				cout << k << ' ';
			}
			else {
				cout << 0 << ' ';
			}
		}
		cout << o_o;
	}
	cout << o_o;
}