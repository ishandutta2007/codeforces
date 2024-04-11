#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	string s,a;
	int k,i,j,c[27];
	cin >> k >> s;
	a=s;
	reverse (a.begin(),a.end());
	j=k-1;
	for (i=0;i<k;i++)
	c[i]=0;
	for (i=0;i<s.size();i++)
	{
		if (s[i]!='?')
		c[s[i]-'a']++;
	}
	for (i=s.size()/2-(1-s.size()%2);i>=0;i--)
	{
		if (s[i]=='?' && a[i]=='?')
		{
			while (c[j]!=0 && j>0)
			j--;
			s[i]='a'+j;
			s[s.size()-i-1]='a'+j;
			c[j]++;
		}
		else if (s[i]=='?' && a[i]!='?')
		s[i]=a[i];
	}
	for (i=0;i<s.size();i++)
	{
		if (s[i]=='?')
		s[i]=s[s.size()-i-1];
	}
	for (i=0;i<s.size();i++)
	{
		if (s[i]!=s[s.size()-i-1])
		{
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	for (i=0;i<k;i++)
	c[i]=0;
	for (i=0;i<s.size();i++)
	c[s[i]-'a']++;
	for (i=0;i<k;i++)
	{
		if (c[i]==0)
		{
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	cout << s;
}