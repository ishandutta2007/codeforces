#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
string s;
bool u0,u1;
int main()
{
	cin>>s;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]=='0')
		{
			if (!u0)
			{
				printf("%d %d\n",3,4);
				u0=1;
			}
			else
			{
				printf("%d %d\n",1,4);
				u0=0;
			}
		}
		else
		{
			if (!u1)
			{
				printf("%d %d\n",1,1);
				u1=1;
			}
			else
			{
				printf("%d %d\n",1,3);
				u1=0;
			}
		}
	}
	return Accepted;
}