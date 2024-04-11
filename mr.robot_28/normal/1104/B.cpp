#include <bits/stdc++.h> 
using namespace std; 
int main() 
{ 
	string s;
	cin >> s;
	int count = 0;
	stack <char> T;
	for(int i = 0; i < s.size(); i++)
	{
		if(i != 0)
		{
			if(T.size() != 0 && T.top() == s[i])
			{
				T.pop();
				count++;
			}
			else
			{
				T.push(s[i]);
			}
		}
		else
		{
			T.push(s[i]);
		}
	}
	if(count % 2 == 0)
	{
		cout << "No";
	}
	else
	{
		cout << "Yes";
	}
	return 0;
}