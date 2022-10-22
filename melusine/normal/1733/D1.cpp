#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
char s1[100005],s2[100005];
int pos[100005],cnt;
int main()
{
	int t,n,x,y;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		x=read();
		y=read();
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		cnt=0;
		for(int i=1;i<=n;i++)if(s1[i]!=s2[i])pos[++cnt]=i;
		if(cnt%2==1)
		{
			printf("-1\n");
			continue;
		}
		if(y<=x)
		{
			if(cnt>=4)
			{
				printf("%lld\n",1LL*(cnt/2)*y);
				continue;
			}
			if(cnt==0)
			{
				printf("0\n");
				continue;
			}
			if(pos[2]-pos[1]==1)printf("%d\n",min(2*y,x));
			else printf("%d\n",y);
		}
	}
	return 0;
}