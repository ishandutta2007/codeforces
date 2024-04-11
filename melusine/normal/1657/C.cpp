#include<iostream>
#include<cstdio>
#include<queue>
#define int long long
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
char s[500005];
signed main()
{
	int t,n,b,now,cs,pn,pc;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",s+1);
		now=1;
		cs=0;
		while(now<=n)
		{
			if(now==n)
			{
				//printf("orz\n");
				break;
			}
			if(s[now]=='(')
			{
				now+=2;
				cs++;
				continue;
			}
			pc=cs;
			pn=now;
			cs++;
			now++;
			while(now<=n&&s[now]!=')')now++;
			if(now==n+1)
			{
				now=pn;
				cs=pc;
				break;
			}
			now++;
		}
		printf("%lld %lld\n",cs,n+1-now);
	}
	return 0;
}