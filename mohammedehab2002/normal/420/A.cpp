#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int i,x,ans=0,test=0,res=0;
	string s,r,l="AHIMOVWXYTU";
	cin >> s;
	r=s;
	reverse(r.begin(),r.end());
	if (r!=s)
	cout << "NO";
	else
	{
		for (i=0;i<s.size();i++)
		{
			for (x=0;x<11;x++)
			{
				if (s[i]==l[x])
				ans++;
				else
				test++;
			}
			if (test!=11)
			res++;
			test=0;
		}
		if (res==s.size())
		cout << "YES";
		else
		cout << "NO";
	}
}