#include<bits/stdc++.h> 
using namespace std;
int main () { 
	string s, t;
	cin >> s >> t;
	if(s.size() == t.size())
	{
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u')
			{
				if(t[i] != 'a' && t[i] != 'e' && t[i] != 'o' && t[i] != 'i' && t[i] != 'u')
				{
					cout << "No";
					return 0;
				}
			}
			else
			{
				if(t[i] == 'a' || t[i] == 'e' || t[i] == 'o' || t[i] == 'i' || t[i] == 'u')
				{
					cout << "No";
					return 0;
				}
			}
		}
	}
	else
	{
		cout << "No";
		return 0;
	}
	cout << "Yes";
	return 0;
}