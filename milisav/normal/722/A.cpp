#include <iostream>
using namespace std;
int t;
char p[6];
int main()
{
	cin>>t;
	cin>>p;
	int h=(p[0]-'0')*10+(p[1]-'0');
	int m=(p[3]-'0')*10+(p[4]-'0');
	int r=0;
	if(m>=60) p[3]='4';
	if(t==24)
	{
		if(h>23) p[0]='0';
	}
	else
	{
		if(h==0) p[0]='1';
		else
		{
			if(h>12)
			{
				if(p[1]=='0') p[0]='1';
				else 
				{
					p[0]='0';
				}
			}
		}
	}
	cout<<p<<endl;
	return 0;
}