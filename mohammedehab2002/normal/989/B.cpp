#include <iostream>
using namespace std;
int main()
{
	int n,p;
	string s;
	cin >> n >> p >> s;
	bool ok=0;
	for (int i=0;i<n-p;i++)
	{
		if (s[i]=='.' && s[i+p]=='.')
		{
			s[i]='0';
			s[i+p]='1';
			ok=1;
		}
		else if (s[i]=='.' && s[i+p]!='.')
		{
			s[i]='1'-s[i+p]+'0';
			ok=1;
		}
		else if (s[i]!='.' && s[i+p]=='.')
		{
			s[i+p]='1'-s[i]+'0';
			ok=1;
		}
		else if (s[i]!=s[i+p])
		ok=1;
	}
	for (int i=0;i<s.size();i++)
	{
		if (s[i]=='.')
		s[i]='0';
	}
	if (ok)
	cout << s;
	else
	cout << "No";
}