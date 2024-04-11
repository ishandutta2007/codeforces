/**
 *    author:  Mohamed.Abo_Okail
 *    created: O2/O1/2O2O
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
	  int a, b, c, d;
	  cin >> a >> b >> c >> d;
	  if(b == c) {
		cout << a << ' ' << d << endl;
	  }
	  else {
		cout << b << ' ' << c << endl;
	  }
	}
}