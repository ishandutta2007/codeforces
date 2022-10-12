/**
 *    author:  Mohamed.Abo_Okail
 *    created: 28/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	
	string s; cin >> s;
	set <int> st;
	for (int i = 0; i < s.size(); i++)
	{
		st.insert(s[i]);
	}
	cout << ((st.size() % 2) ? "IGNORE HIM!" : "CHAT WITH HER!") << endl;
}