#include<bits/stdc++.h>
using namespace std;
char s[1010];int map[6][6];
int main()
{
	int n,i,j,c1=0,c2=0;cin>>s;n=strlen(s);
	for (i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			if (c1)puts("1 3");
			else puts("1 1");
			c1^=1;
		}
		else
		{
			cout<<"3 "<<++c2<<endl;
			c2%=4;
		}
	}
}