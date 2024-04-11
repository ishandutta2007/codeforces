/**
 *    author:  Mohamed.Abo_Okail
 *    created: 15/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	
	int t; cin >> t;
	while(t--)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		cout << (a + b + c) / 2 << endl;
	}
}