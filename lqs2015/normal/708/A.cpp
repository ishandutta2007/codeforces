#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,pos;
char s[111111];
int main()
{
	scanf("%s",s);
	n=strlen(s);
	pos=0;
	while(pos<n && s[pos]=='a') pos++;
	if (pos==n)
	{
		s[n-1]='z';
		printf("%s\n",s);
		return 0;
	}
	while(pos<n && s[pos]!='a') 
	{
		s[pos]--;
		pos++;
	}
	printf("%s\n",s);
	return 0;
}