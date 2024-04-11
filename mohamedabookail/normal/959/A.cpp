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
	
	ll n; cin >> n;
	cout << ((n & 1) ? "Ehab" : "Mahmoud") << endl;
}