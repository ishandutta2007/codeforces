#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
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
void output(int x)
{
	if(x<=9)printf("0");
	printf("%lld",x);
}
signed main()
{
	int h1,t1,h2,t2;
	scanf("%lld:%lld",&h1,&t1);
	scanf("%lld:%lld",&h2,&t2);
	int ha,ta;
	if(t1-t2<0)ta=t1-t2+60,h1--;
	else ta=t1-t2;
	if(h1-h2<0)ha=h1-h2+24;
	else ha=h1-h2;
	output(ha);
	printf(":");
	output(ta);
	return 0;
}