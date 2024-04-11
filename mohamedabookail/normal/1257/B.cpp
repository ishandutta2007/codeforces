/**
 *    author:  Mohamed.Abo_Okail
 *    created: 12/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

ll gcd(int x, int y)
{
	return ((!y) ? x : gcd(y, x % y));
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	
	ll t; cin >> t;
	while(t--)
	{
		ll x, y;
		cin >> x >> y;
		
		if(x == 1 || x == 2 || x == 3)
		{
			if((y == 3 || y == 2 || y == 1) && (x >= y) || (x == 2 && y == 3) )
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else
			cout << "YES" << endl;

	}


}