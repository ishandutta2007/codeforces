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
	int n; cin >> n;
	for (int i = 1; i < 40; i++) {
		if(i * (i + 1) / 2 == n) {
			return cout << "YES" << o_o, 0;
		}
	}
	cout << "NO" << endl;
}