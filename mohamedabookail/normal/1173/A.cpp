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
	
	int x, y, z;
	cin >> x >> y >> z;
	
	if(x > y + z)
		cout << '+' << endl;
	else if(y > x + z)
		cout << '-' << endl;
	else if((x + z) == (y + z) && (x == y + z) && (y == x + z))
		cout << 0 << endl;
	else
		cout << '?' << endl;
}