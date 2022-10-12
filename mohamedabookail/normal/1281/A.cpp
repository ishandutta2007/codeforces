/**
 *    author:  Mohamed.Abo_Okail
 *    created: 22/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	
	int t; cin >> t;
	while(t--)
	{
		string s; cin >> s;
		if(s[s.size() -1] == 'o') {
			cout << "FILIPINO" << endl;
		}
		else if(s[s.size() - 1] == 'u') {
			cout << "JAPANESE" << endl;
		}
		else {
			cout << "KOREAN" << endl;
		}
	}
}