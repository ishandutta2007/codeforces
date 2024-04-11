#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
map<string,int> m;
int main()
{
	int q;
	scanf("%d",&q);
	while (q--)
	{
		char c;
		string a;
		cin >> c >> a;
		if (c=='+')
		{
			string c="";
			for (int i=(int)a.size()-1;i>(int)a.size()-19;i--)
			{
				if (i>=0)
				c=(char)((a[i]-'0')%2+'0')+c;
				else
				c='0'+c;
			}
			m[c]++;
		}
		else if (c=='-')
		{
			string c="";
			for (int i=(int)a.size()-1;i>(int)a.size()-19;i--)
			{
				if (i>=0)
				c=(char)((a[i]-'0')%2+'0')+c;
				else
				c='0'+c;
			}
			m[c]--;
		}
		else
		{
			string c="";
			for (int i=(int)a.size()-1;i>(int)a.size()-19;i--)
			{
				if (i>=0)
				c=a[i]+c;
				else
				c='0'+c;
			}
			printf("%d\n",m[c]);
		}
	}
}