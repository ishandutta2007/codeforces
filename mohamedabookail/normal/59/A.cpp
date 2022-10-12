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
	
	string s; cin >> s;
	int ca = 0, sm = 0;
	bool bb = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
			sm++;
		else
			ca++;
	}
	if(sm >= ca) bb = 1;
	for (int i = 0; i < s.size(); i++)
	{
		s[i] = (bb) ? tolower(s[i]) : toupper(s[i]);
	}
	cout << s << endl;
}