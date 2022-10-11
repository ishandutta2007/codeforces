#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,c=0,lc;
	string s,s2;
	cin >> n >> s;
	s2=s;
	for (int i=0;i<n;i++)
	{
		if (s[i]!='.')
		c++;
	}
	do {
		lc=c;
		for (int i=0;i<n;i++)
		{
			if (s[i]=='R' && i!=n-1)
			{
				if (s[i+1]=='.')
				{
					if (i==n-2)
					{
						s2[n-1]='R';
						c++;
					}
					else
					{
						if (s[i+2]=='.' || s[i+2]=='R')
						{
							s2[i+1]='R';
							c++;
						}
					}
				}
			}
			else if (s[i]=='L' && i)
			{
				if (s[i-1]=='.')
				{
					if (i==1)
					{
						s2[0]='L';
						c++;
					}
					else
					{
						if (s[i-2]=='.' || s[i-2]=='L')
						{
							s2[i-1]='L';
							c++;
						}
					}
				}
			}
		}
		s=s2;
	}while(c!=lc);
	cout << n-c;
}