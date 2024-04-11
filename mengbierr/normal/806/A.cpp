#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f;
}
int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}
int main()
{
	int t=read();
	while(t--)
	{
		int p=read(),q=read(),a=read(),b=read();
		if(a==b)
		{
			if(p==q)
			puts("0");
			else puts("-1");
			continue;
		}
		if(a==0)
		{
			if(p==0)
			puts("0");
			else puts("-1");
			continue;
		}
		int x=gcd(a,b);
		a/=x;b/=x;
		long long ans=p/a;
		if(p%a) ans++;
		long long ans2=(q-p)/(b-a);
		if((q-p)%(b-a)) ans2++;
		printf("%I64d\n",1LL*max(ans,ans2)*(long long)b-(long long)q);
	}
}