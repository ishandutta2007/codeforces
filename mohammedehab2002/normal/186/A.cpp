#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int i,x=0,test=0,t[2];
	string s,a;
	cin >> s >> a;
	if (s.size()!=a.size())
	{
		cout << "NO";
		return 0;
	}
	for (i=0;i<s.size();i++)
	{
		if (s[i]!=a[i])
		test++;
	}
	if (test!=2 && test!=0)
	cout << "NO";
	else
	{
		if (test==2)
		{
			for (i=0;i<s.size();i++)
			{
				if (s[i]!=a[i])
				{
					t[x]=i;
					x++;
				}
			}
			swap (s[t[0]],s[t[1]]);
			if (s==a)
			cout << "YES";
			else
			cout << "NO";
		}
		else
		{
			for (i=0;i<s.size();i++)
			{
				if (s.rfind(s[i])!=s.find(s[i]))
				{
					test=1;
					goto out;
				}
			}
			out: if (test==1)
			cout << "YES";
			else
			cout << "NO";
		}
	}
}