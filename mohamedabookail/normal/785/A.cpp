/**
 *    author:  Mohamed.Abo_Okail
 *    created: 05/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	//freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
	
	map <string, int> mp;
	mp["Tetrahedron"] = 4;
	mp["Cube"] = 6;
	mp["Octahedron"] = 8;
	mp["Dodecahedron"] = 12;
	mp["Icosahedron"] = 20;
	ll ans = 0;
	ll n; cin >> n;
	while(n--)
	{
		string s; cin >> s;
		ans += mp[s];
	}
	cout << ans << endl;
}