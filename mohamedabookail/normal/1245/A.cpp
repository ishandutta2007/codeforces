/**
 *    author:  Mohamed.Abo_Okail
 *    created: 08/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

ll _gcd(ll x, ll y)
{
	return ((!y) ? x : _gcd(y, x % y));
}
int main()
{
	std::ios_base::sync_with_stdio(0);
	//freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
	
	int t; cin >> t;
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		if(_gcd(a, b) == 1)
			cout << "Finite" << endl;
		else
			cout << "Infinite" << endl;
	}
}