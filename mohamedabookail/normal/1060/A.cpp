/**
 *    author:  Mohamed Abo_Okail
 *    created: 16/O1/2O2O
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int n; string s; cin >> n >> s;
	int c = 0;
	for (int i = 0; i < n; i++) {
		if(s[i] == '8') { c++; }
	}
	cout << min(n / 11, c) << endl;
}