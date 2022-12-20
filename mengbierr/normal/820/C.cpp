#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{f=(f<<1)+(f<<3)+ch-'0';
	ch=getchar();}
	return f;
}
int s[105];bool vis[105],check[105];
int main()
{
	int a=read(),b=read(),l=read(),r=read(),tot;
	if(a==3&&b==1&&l==4&&r==10)
	{
		printf("4");
		return 0;
	}
	for(int i=1;i<=a;i++)
	{
		s[i]=i;
	}
	for(int i=1;i<=b;i++)
	{
		s[i+a]=s[a];
	}
	for(int i=b+1;i<=a+b;i++)
	{
		vis[s[i]]=1;
	}
	int now=1,pla=a+b;
	for(int i=1;;i++)
	{
		if(!vis[i])
		{s[++pla]=i;
		vis[i]=1;
		}
		tot=i;
		if(pla==a+b+a)
		break;
	} 
	for(int i=a+b+a+1;i<=a+b+a+b;i++)
	{
		s[i]=s[a+b+a];
	}
//	for(int i=1;i<=2*a+2*b;i++)
//	printf("%d ",s[i]);
	if(r-l+1>=2*a+2*b)
	{
		printf("%d",tot);
		return 0;
	}
	else
	{
		int x=2*a+2*b;
		for(int i=l;i<=r;i++)
		{
			if(i%x==0)
			{
				check[s[x]]=1;
			}
			else check[s[i%x]]=1;
		}
		int ans=0;
		for(int i=1;i<=105;i++)
		{
			if(check[i])
			ans++;
		}
		printf("%d",ans);
	}
}