#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,S,prime[20000000],tot,ans[6010];
bool p[20000000];
void get_prime(int n)
{
	p[1]=true;
	for(int i=2;i<=n;i++)
	{
		if(!p[i]) prime[++tot]=i;
		for(int j=1;j<=tot&&i*prime[j]<=n;j++)
			p[i*prime[j]]=true;
	}
	for(int i=1;i<=n;i++)
		if(p[i]) p[i]=false;
		else p[i]=true;
}
int main()
{
	scanf("%d",&n);
	S=(1+n)*n/2;
	get_prime(S);
	if(S%2==0)
	{
		for(int i=1;i<=S;i++)
			if(p[i]&&p[S-i])
			{
				for(int j=1;j<=n;j++)
					if(i==j) putchar('1'),putchar(' ');
					else putchar('2'),putchar(' ');
				return 0;
			}
	}
	else
	{
		if(n==1) {puts("-1");return 0;}
		if(n==2) {puts("1 1");return 0;}
		if(p[S])
		{
			for(int i=1;i<=n;i++) putchar('1'),putchar(' ');
			return 0;
		}
		if(p[S-2])
		{
			putchar('1'),putchar(' ');
			putchar('2'),putchar(' ');
			for(int i=3;i<=n;i++) putchar('1'),putchar(' ');
			return 0;
		}
		ans[3]=3;
		S-=3;
		for(int i=4;i<=S;i++)
			if(p[i]&&p[S-i]) {ans[i]=2;break;}
		for(int i=1;i<=n;i++)
		{
			if(ans[i]==0) ans[i]=1;
			printf("%d ",ans[i]);
		}
	}
	return 0;
}