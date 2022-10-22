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
int a[100005];
int ql[100005],qr[100005],cnt;
int main()
{
	int t,n,x,y;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		if(n==1)
		{
		    printf("0\n");
		    continue;
		}
		cnt=0;
		ql[++cnt]=1;
		qr[cnt]=n;
		if((a[1]+a[n])%2==0)a[1]=a[n];
		else a[n]=a[1];
		for(int i=2;i<=n-1;i++)
		{
			if((a[i]+a[1])%2==0)
			{
				ql[++cnt]=i;
				qr[cnt]=n;
			}
			else
			{
				ql[++cnt]=1;
				qr[cnt]=i;
			}
		}
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++)printf("%d %d\n",ql[i],qr[i]);
	}
	return 0;
}