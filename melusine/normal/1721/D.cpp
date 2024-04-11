#include<iostream>
#include<cstdio>
#include<map>
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
int a[200005],b[200005];
map<int,int>ma;
int n;
bool check(int x)
{
	ma.clear();
	for(int i=1;i<=n;i++)
	{
		ma[(a[i]&x)^x]++;
	} 
	for(int i=1;i<=n;i++)
	{
		if(ma[b[i]&x]==0)return false;
		ma[b[i]&x]--;
	}
	return true;
}
int main()
{
	int t,now;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
		}
		for(int i=1;i<=n;i++)
		{
			b[i]=read();
		}
		now=0;
		for(int i=29;i>=0;i--)
		{
			if(check(now+(1<<i)))now+=(1<<i);
		}
		printf("%d\n",now);
	}
	return 0;
}