#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		if(s[s.size() - 2]== 'p' && s[s.size() - 1] == 'o')
		{
			cout << "FILIPINO\n";
		}
		else if(s[s.size() - 4] == 'd' && s[s.size() - 3] == 'e' && s[s.size() - 2] == 's' && s[s.size() - 1] == 'u')
		{
			cout << "JAPANESE\n";
		}
		else if(s[s.size() - 4] == 'm' && s[s.size() - 3] == 'a' && s[s.size() - 2] == 's' && s[s.size() - 1] == 'u')
		{
			cout << "JAPANESE\n";
		}
		else 
		{
			cout << "KOREAN\n";
		}
	}
	return 0;
}