#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
	string line;
	int p=0,i,m=0,l;
	getline(cin,line);
	l=line.size();
	while (line!="")
	{
		if (line[0]=='+')
		p++;
		else if (line[0]=='-')
		p--;
		else
		{
			l=line.size();
			for (i=0;i<l;i++)
			{
				if (line[i]==':')
				l-=(i+1);
			}
			m+=(l*p);
		}
		getline(cin,line);
	}
	cout << m;
}