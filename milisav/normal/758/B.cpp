#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
char s[10000];
int k[4];
int l[4];
int main()
{
	scanf("%s",s);
	n=strlen(s);
	k[0]=0;
	k[1]=0;
	k[2]=0;
	k[3]=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='!') k[i%4]++;
		else
		{
			if(s[i]=='R') l[0]=i%4;
			else
			{
				if(s[i]=='B') l[1]=i%4;
				else
				{
					if(s[i]=='Y') l[2]=i%4;
					else l[3]=i%4;
				}
			}
		}
	}
	printf("%d %d %d %d",k[l[0]],k[l[1]],k[l[2]],k[l[3]]);
	return 0;
}