#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int i,ans=0;
	string s;
	cin >> s;
	for (i=0;i<s.size();i++)
	{
		if (s[i]=='4' || s[i]=='7')
		ans++;
	}
	if (ans==4 || ans==7)
	cout << "YES";
	else
	cout << "NO";
}