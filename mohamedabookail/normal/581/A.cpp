/**
 *    author:  Mohamed.Abo_Okail
 *    created: 23/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int a, b; cin >> a >> b;
	if(a < b) swap(a, b);
	cout << b << ' ' << (a - b) / 2 << endl;
}