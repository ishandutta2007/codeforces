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
	
	string a; cin >> a;
	for (int i = 0; i < 5; i++)
	{
		string b; cin >> b;
		if(a[0] == b[0] || a[1] == b[1])
			return cout << "YES" << endl, 0;
	}

	cout << "NO" << endl;

}