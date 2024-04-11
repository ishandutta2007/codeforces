#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
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
signed main()
{
	int a,b,w,x,c;
	a=read();
	b=read();
	w=read();
	x=read();
	c=read();
	printf("%lld\n",max(0LL,(-b+c*w-a*w+w-x-1)/(w-x)));
	return 0;
}