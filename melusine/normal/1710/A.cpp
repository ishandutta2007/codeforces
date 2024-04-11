#include<iostream>
#include<cstdio>
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
int a[100005];
signed main()
{
	int t,n,m,k;
	t=read();
	bool flag;
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		k=read();
		flag=false;
		for(int i=1;i<=k;i++)
		{
			a[i]=read();
			if(a[i]>=n*m)flag=true;
		}
		if(flag==true)
		{
			printf("Yes\n");
			continue;
		}
		int sl1=0,sl2=0;
		bool flag1=false,flag2=false;
		for(int i=1;i<=k;i++)
		{
			if(a[i]>=2*n)sl1+=a[i]/n;
			if(a[i]>=3*n)flag1=true;
			if(a[i]>=2*m)sl2+=a[i]/m;
			if(a[i]>=3*m)flag2=true;
		}
		if(sl1>=m&&(flag1==true||m%2==0))
		{
			printf("Yes\n");
			continue;
		}
		if(sl2>=n&&(flag2==true||n%2==0))
		{
			printf("Yes\n");
			continue;
		}
		printf("No\n");
	}
	return 0;
}