#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char c[101000];
int main()
{
	scanf("%s",c);
	int len=strlen(c);
	int s=0;bool ok=0;
	for(int i=0;i<len;i++)if(c[i]=='1')s++;
	for(int i=0;i<len;i++)
	{
		if(c[i]!='1')
		{
			if(c[i]=='0'||ok)printf("%c",c[i]);
			else 
			{
				for(int j=1;j<=s;j++)printf("1");
				ok=1;printf("2");
			}
		}
	}
	if(!ok)
	for(int i=1;i<=s;i++)printf("1");
	return 0;
}