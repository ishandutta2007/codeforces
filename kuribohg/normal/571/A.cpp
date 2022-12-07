#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
int a,b,c,L,S;
LL ans;
LL F3(LL n)
{
	return (n+3)*(n+2)/2LL*(n+1)/3LL;
}
LL F2(LL n)
{
	if(n<0) return 0;
	return (n+2)*(n+1)/2LL;
}
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&L);
	S=a+b+c+L;
	ans=F3(L);
	for(int i=a;i<=S;i++)
	{
		int x=min(L-(i-a),i-b-c);
		ans-=F2(x);
	}
	for(int i=b;i<=S;i++)
	{
		int x=min(L-(i-b),i-a-c);
		ans-=F2(x);
	}
	for(int i=c;i<=S;i++)
	{
		int x=min(L-(i-c),i-a-b);
		ans-=F2(x);
	}
	printf("%I64d\n",ans);
	return 0;
}