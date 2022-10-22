#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
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
int a[500005];
int qzh[500005];
char xz[500005]; 
signed main()
{
	int t,n,q,sth,fl;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		bool flag=false;
		fl=1;
		for(int i=1;i<=n-1;i++)
		{
			fl=max(1,fl-1);
			for(int j=fl;j<=n-i;j++)a[j]=a[j+1]-a[j];
			sort(a+fl,a+n-i+1);
			while(fl<=n-i&&a[fl]==0)fl++;
			if(i<n-1&&a[n-i-1]==0)
			{
				flag=true;
				printf("%d\n",a[n-i]);
				break;
			}
		}
		if(flag==true)continue;
		printf("%d\n",a[1]);
	}
	return 0;
}