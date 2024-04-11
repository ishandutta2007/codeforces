#include<bits/stdc++.h>
using namespace std;
int n,l,sum;
char s[111];
bool f1,f2;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		l=strlen(s);
		f1=f2=0;sum=0;
		for (int j=0;j<l;j++)
		{
			if (s[j]=='0') 
			{
				if (!f1) f1=1;
				else f2=1;
			}
			else
			{
				if ((s[j]-'0')%2==0) f2=1;
				sum+=(s[j]-'0');
			}
		}
		if (f1 && f2 && sum%3==0) printf("red\n");
		else printf("cyan\n");
	}
	return 0;
}