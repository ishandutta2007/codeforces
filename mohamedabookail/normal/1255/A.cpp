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
	
	int t; cin >> t;
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		a = abs(a - b);
		cout << (a / 5) + ((a % 5) / 2) + ((a % 5) % 2) << endl;
	}
}