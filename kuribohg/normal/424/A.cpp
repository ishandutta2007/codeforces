#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
char a[220];
int num1,num2;
int main()
{
	scanf("%d%s",&n,a);
	for(int i=0;i<n;i++)
		if(a[i]=='X') num1++;
		else num2++;
	if(num1>(n>>1))
	{
		printf("%d\n",num1-(n>>1));
		int i=0;
		while(num1>(n>>1))
		{
			for(;i<n;i++)
			{
				if(a[i]=='X')
				{
					a[i]='x';
					break;
				}
			}
			num1--;
		}
		printf("%s\n",a);
	}
	else if(num2>(n>>1))
	{
		printf("%d\n",num2-(n>>1));
		int i=0;
		while(num2>(n>>1))
		{
			for(;i<n;i++)
			{
				if(a[i]=='x')
				{
					a[i]='X';
					break;	
				}
			}
			num2--;
		}
		printf("%s\n",a);
	}
	else
	{
		printf("0\n%s\n",a);
	}
	return 0;
}