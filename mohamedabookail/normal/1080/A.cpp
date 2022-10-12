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
	
	ll n, k;
	cin >> n >> k;
	ll a = (2 * n), b = (5 * n), c = (8 * n);
	a = (a + k - 1) / k;
	b = (b + k - 1) / k;
	c = (c + k - 1) / k;
	cout << (a + b + c) << endl;

}