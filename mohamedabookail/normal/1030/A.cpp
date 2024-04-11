/**
 *    author:  Mohamed.Abo_Okail
 *    created: 29/10/2019
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
	
	int n; cin >> n;
	while(n--)
	{
		int a; cin >> a;
		if(a) return cout << "HARD" << endl, 0;
	}

	cout << "EASY" << endl;
}