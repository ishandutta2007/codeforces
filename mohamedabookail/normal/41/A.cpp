/**
 *    author:  Mohamed.Abo_Okail
 *    created: 26/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	string s, t; cin >> s >> t;
	reverse(t.begin(), t.end());
	cout << ((s == t) ? "YES" : "NO") << endl;
}