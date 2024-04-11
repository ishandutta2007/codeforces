#include<iostream>
#include<cstdio>
#include<algorithm> 
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
int qzh[100005],a[100005];
signed main()
{
	int t,n,k;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		if(k==1)
		{
			qzh[n]=read();
			printf("YES\n");
			continue;
		}
		for(int i=n-k+1;i<=n;i++)qzh[i]=read();
		for(int i=n-k+2;i<=n;i++)a[i]=qzh[i]-qzh[i-1];
		bool flag=true;
		for(int i=n-k+3;i<=n;i++)
		{
			if(a[i]<a[i-1])
			{
				flag=false;
				break;
			}
		}
		if(flag==false)
		{
			printf("NO\n");
			continue;
		}
		int maxn=0;
		if(qzh[n-k+1]>=0)maxn=(qzh[n-k+1]+n-k)/(n-k+1);
		else maxn=-((-qzh[n-k+1])/(n-k+1));
		if(maxn>a[n-k+2])
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
	}
	return 0;
}