/**
 *    author:  Mohamed Abo_Okail
 *    created: 23/O1/2O2O
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
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int oo; cin >> oo;
			sum += oo;
		}
		cout << (sum + n - 1) / n << o_o;
	}
}