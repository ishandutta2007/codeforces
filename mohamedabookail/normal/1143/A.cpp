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
	
	int n; cin >> n;
	int c1 = 0, c0 = 0;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		if(a) c1 = i;
		else c0 = i;
	}

	cout << min(c0, c1) + 1 << endl;
}