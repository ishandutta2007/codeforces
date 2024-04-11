#include<bits/stdc++.h>
using namespace std;
const int N=55;
int cmp(char a,char b)
{
	if(a=='?'||b=='?') return 1;
	return a==b;
}
int t,n;
char a[N],c[N];
char b[N]={'a','b','a','c','a','b','a'};
int check()
{
	int cnt=0;
	for(int i=1;i<=n-6;i++)
	{
		int flag=0;
		for(int j=i;j<=i+6;j++)
		{
			if(c[j]!=b[j-i]) flag=1;
		}		
		if(!flag) cnt++;
	}
	return cnt==1;
}
int main()
{
	scanf("%d",&t);
	for(int am=1;am<=t;am++)
	{
		scanf("%d",&n);
		scanf("%s",a+1);
		int ans=0;
		for(int i=1;i<=n-6;i++)
		{
			int flag=0;
			for(int j=i;j<=i+6;j++)
			{
				if(!cmp(b[j-i],a[j])) flag=1;
			}
			if(flag) continue;
			for(int j=1;j<=n;j++) c[j]=a[j];
			for(int j=i;j<=i+6;j++)
			{
				if(c[j]=='?')
				{
					c[j]=b[j-i];
				}
			}			
			if(check())
			{
				ans=1;
				break;
			}
		}
		if(ans)
		{
			printf("Yes\n");
			for(int i=1;i<=n;i++) printf("%c",c[i]=='?'?'z':c[i]);
			printf("\n");
		}
		else printf("No\n");
	}
	return 0;
}