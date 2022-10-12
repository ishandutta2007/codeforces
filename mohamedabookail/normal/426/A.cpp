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
	int n, s; cin >> n >> s;
	int nemo = 0, mx = -1;
	while(n--) {
		int oo; cin >> oo;
		nemo += oo;
		mx = max(mx, oo);
	}
	cout << ((nemo - mx <= s) ? "YES" : "NO") << o_o;
}