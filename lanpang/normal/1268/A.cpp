#include<bits/stdc++.h>
using namespace std;

int n,k,now,lst;
char xh[200010];
char s[200010];
bool flag;

int main()
{
	scanf("%d%d",&n,&k);
	gets(s);
	gets(s);
	for(int i=1;i<=k;i++) xh[i]=s[i-1];
	flag=0;
	now=1;
	for(int i=k+1;i<=n;i++)
	{
		if(s[i-1]>xh[now])
		{
			flag=1;
			break;
		}
		if(s[i-1]<xh[now]) break;
		now++;
		if(now>k) now=1;
	}
	if(flag)
	{
		lst=k;
		while(xh[lst]=='9') lst--;
		xh[lst]=xh[lst]+1;
		lst++;
		while(lst<=k) xh[lst++]='0';
	}
	now=1;
	for(int i=1;i<=n;i++)
	{
		s[i-1]=xh[now];
		now++;
		if(now>k) now=1;
	}
	printf("%d\n",n);
	puts(s);
	return 0;
}