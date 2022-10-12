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
	vector < int > v(n);
	map < int, int > mp;
	int oo, nemo = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i] >> oo;
		mp[oo]++;
	}
	for (int i = 0; i < n; i++) {
		nemo += mp[v[i]];
	}
	cout << nemo << o_o;
}