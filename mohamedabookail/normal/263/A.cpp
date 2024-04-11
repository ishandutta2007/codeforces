/**
 *    author:  Mohamed.Abo_Okail
 *    created: 27/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int a; cin >> a;
			if(a)
				return cout << abs(2 - i) + abs( 2 - j) << endl, 0;
		}
	}
}