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
int main()
{
	int t,l1,r1,l2,r2,sth;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		l1=read();
		r1=read();
		l2=read();
		r2=read();
		sth=max(l1,l2);
		if(sth>=l1&&sth<=r1&&sth>=l2&&sth<=r2)
		{
			printf("%d\n",sth);
			continue;
		}
		printf("%d\n",l1+l2);
	}
	return 0;
}