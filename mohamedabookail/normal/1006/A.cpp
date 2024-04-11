/**
 *    author:  Mohamed.Abo_Okail
 *    created: 24/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	

	int n; cin >> n;
	while(n--)
	{
		int a; cin >> a;
		cout << ((a % 2) ? a : a - 1);
		cout << " ";
	}
}