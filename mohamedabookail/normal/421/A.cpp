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
	int n, a, b; cin >> n >> a >> b;
	map < int, bool > mp;
	for (int i = 0; i < a; i++) {
		int oo; cin >> oo;
		mp[oo] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if(mp[i]) { cout << 1 << ' '; }
		else { cout << 2 << ' '; }
	}
	cout << o_o;
}