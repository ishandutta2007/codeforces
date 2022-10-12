/**
 *    author:  Mohamed.Abo_Okail
 *    created: 30/10/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	//freopen("distinct.in", "r", stdin);
	//freopen("out.out", "w", stdout);
	
	string s; cin >> s;
	char ch = s[0];
	for (int i = 0; i < s.size(); i++)
	{
		cout << ((ch >= s[i]) ? "Mike" : "Ann") << endl;
		ch = min(ch, s[i]);
	}
}