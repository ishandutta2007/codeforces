#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int cnt[1000];char c[1010000];
int main()
{
	scanf("%s",c);
	int len=strlen(c);
	for(int i=0;i<len;i++)c[i+len]=c[i];
	int ans=1;
	int s=1;
	for(int i=1;i<2*len;i++)
	{
		if(c[i]==c[i-1])s=1;
		else s++;
		ans=max(ans,s);
	}
	printf("%d\n",min(ans,len));
	return 0;
 }