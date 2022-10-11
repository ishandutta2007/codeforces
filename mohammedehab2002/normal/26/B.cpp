#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int o=0;
	string s;
	cin >> s;
	int ans=s.size();
	for (int i=0;i<s.size();i++)
	{
		if (!o && s[i]==')')
		ans--;
		if (s[i]=='(')
		o++;
		else if (s[i]==')' && o)
		o--;
	}
	cout << ans-o;
}