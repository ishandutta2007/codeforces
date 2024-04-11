/**
 *    author:  Mohamed.Abo_Okail
 *    created: 27/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	
	string s; getline(cin, s);
	set <char> st;
	for (int i = 0; i < s.size(); i++)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
			st.insert(s[i]);
	}
	cout << st.size() << endl;
}