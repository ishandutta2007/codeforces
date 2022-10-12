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
	int n, m; cin >> n >> m;
	int a = 0, b = 0, c = 0, d = 0;
	for (int i = 0; i < n; i++) {
	    int x; cin >> x;
		if(x % 2) { a++; }
		if(!(x % 2)) { b++; }
	}
	for (int i = 0; i < m; i++) {
	    int x; cin >> x;
		if(x % 2) { c++; }
	    if(!(x % 2)) { d++; }
	}
	cout << min(a, d) + min(b, c) << endl;
}