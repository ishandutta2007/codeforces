/**
 *    author:  Mohamed.Abo_Okail
 *    created: 15/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	
	int n; cin >> n;

	if(n % 4 == 0)
		cout << 1 << " " << 'A' << endl;
	else if(n % 4 == 1)
		cout << 0 << " " << 'A' << endl;
	else if(n % 4 == 2)
		cout << 1 << " " << 'B' << endl;
	else
		cout << 2 << " " << 'A' << endl;
}