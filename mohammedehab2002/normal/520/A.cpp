#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;
int main()
{
	int n,arr[26],i,ans=0;
	string s;
	cin >> n >> s;
	for (i=0;i<26;i++)
	arr[i]=0;
	for (i=0;i<s.size();i++)
	{
		if (isupper(s[i]))
		s[i]=tolower(s[i]);
		if (arr[s[i]-'a']==0)
		{
			ans++;
			arr[s[i]-'a']++;
		}
		else
		arr[s[i]-'a']++;
	}
	if (ans<26)
	cout << "NO";
	else
	cout << "YES";
}