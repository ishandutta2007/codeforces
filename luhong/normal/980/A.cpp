#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int s1=0,s2=0;
char s[1010];
int main()
{
	scanf("%s",s);int n=strlen(s);
	for(int i=0;i<n;i++)
	{
		if(s[i]=='-')s1++;
		if(s[i]=='o')s2++;
	}
	if(s1==0||s2==0)return 0*puts("YES");
	if(s1%s2==0)puts("YES");else puts("NO");
	return 0;
 }