#include<iostream>
#include<cstdio>
using namespace std;
char a[2000];
int n,ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",a);
		if (a[0]=='T') ans+=4;
		else if (a[0]=='C') ans+=6;
		else if (a[0]=='O') ans+=8;
		else if (a[0]=='D') ans+=12;
		else ans+=20;
	}
	printf("%d\n",ans);
	return 0;
 }