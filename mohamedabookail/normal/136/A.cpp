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
	
	int n; cin >> n;
	map <int, int> mp;
	for (int i = 1; i <= n; i++)
	{
		int a; cin >> a;
		mp[a] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << mp[i] << " ";
	}
}