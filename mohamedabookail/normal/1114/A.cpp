/**
 *    author:  Mohamed.Abo_Okail
 *    created: 02/01/2020
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int x, y, z, a, b, c;
	cin >> x >> y >> z >> a >> b >> c;
	a -= x; b += a; b -= y; c += b; c -= z;
	if(a < 0 || b < 0 || c < 0) {
	    cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}
}