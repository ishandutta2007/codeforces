/**
 *    author:  Mohamed.Abo_Okail
 *    created: 20/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"
 
int main()
{
	std::ios_base::sync_with_stdio(0);
	
	ll a, b, c;
	cin >> a >> b >> c;
	a += c, b += c;
	if(a > b) swap(a, b);
	cout << a + min(b, a + 1) << endl;
}