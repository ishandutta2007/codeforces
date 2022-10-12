/**
 *    author:  Mohamed.Abo_Okail
 *    created: 12/11/2019
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
		int n, x, a, b;
		cin >> n >> x >> a >> b;
		if(abs(a - b) == (n - 1))
			cout << abs(a - b) << endl;
		else if(abs(a - b) + x < (n - 1))
			cout << abs(a - b) + x << endl;
		else
			cout << n - 1 << endl;
	}
}