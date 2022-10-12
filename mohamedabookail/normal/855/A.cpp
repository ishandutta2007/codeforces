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
	
	int t; cin >> t;
	map <string, int> mp;
	while(t--) {
		string s; cin >> s;
		mp[s]++;
		if(mp[s] >= 2) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}