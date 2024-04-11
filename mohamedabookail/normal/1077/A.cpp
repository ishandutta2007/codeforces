/**
 *    author:  Mohamed.Abo_Okail
 *    created: 21/11/2019
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
		ll a, b, n;
		cin >> a >> b >> n;

		cout << (((n + 1) / 2) * a) - ((n / 2) * b) << endl;
	}
}